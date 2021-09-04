from itertools import zip_longest, combinations
from math import sqrt
from typing import Tuple
import heapq

def str_to_int_list(input_str: str) -> list:
    return list(map(int,input_str.strip().split(" ")))

def cal_dist_sq(x: Tuple[int, int], y: Tuple[int, int]) -> int:
    return ((x[0]-y[0])**2 + (x[1]-y[1])**2)

def cal_dist_g(b_set1: set, b_set2: set, b_list: list) -> float:
    min_dist = float("INF")
    for b1 in b_set1:
        for b2 in b_set2:
            min_dist_nom = cal_dist_sq(b_list[b1], b_list[b2])
            if min_dist_nom <  min_dist:
                min_dist = min_dist_nom
    return min_dist
 
def get_min_dist_list(num: int, g_dist_dict: dict) -> list:
    included = {i:False for i in range(num)}
    c_list = []
    e_priority_q = []
    heapq.heappush(e_priority_q,(0,(0,0)))
    
    while False in included.values():
        dist, v_tup = heapq.heappop(e_priority_q)
        u, v = v_tup
        if included[v] == False:
            c_list.append(dist)
            included[v] = True
            for i in range(num):
                if i != v and included[i] == False:
                    heapq.heappush( 
                        e_priority_q,
                        (g_dist_dict[(i, v)], (i, v))
                        if i < v 
                        else (g_dist_dict[(v, i)], (v, i))
                    )
        elif included[u] == False:
            c_list.append(dist)
            included[u] = True
            for i in range(num):
                if i != u and included[i] == False:
                    heapq.heappush( 
                        e_priority_q,
                        (g_dist_dict[(i, u)], (i, u))
                        if i < u 
                        else (g_dist_dict[(u, i)], (u, i))
                    )
        else: 
            pass
    return c_list

def find_min_b(dist_dict:dict):
    min_k, min_dist = None, float("INF")
    
    for k, v in dist_dict.items():
        if v[0] != 0 and v[0] < min_dist:
            min_k, min_v = k, v[0]
    return min_k
 
for _ in range(int(input().strip())):
    b_num, c_num = tuple(map(int,input().strip().split(" ")))
    b_list = list(
        zip_longest(
            *map(
                str_to_int_list,
                (input(), input())
            )
        )
    )
    dist_dict = {b: (float("INF"), None) for b in range(b_num)} 
    # 각각이 연결된 건물그룹의 리스트 
    b_set_list = []
    c_list = []
    for _ in range(c_num):
        u, v = str_to_int_list(input())
        is_break = False
        for b_set in b_set_list:
            if u in b_set and v in b_set:
                is_break = True
                break
            elif u in b_set and v not in b_set:
                b_set.add(v)
                dist_dict = {b: (
                        cal_dist_sq(b_list[v], b_list[b]),
                        v
                    ) if cal_dist_sq(b_list[v], b_list[b]) < dist_dict[b][0]
                    else dist_dict[b]
                    for b in range(b_num)
                }
                is_break = True
                break
            elif u not in b_set and v in b_set:
                b_set.add(u)
                dist_dict = {b: (
                        cal_dist_sq(b_list[u], b_list[b]),
                        u
                    ) if cal_dist_sq(b_list[u], b_list[b]) < dist_dict[b][0]
                    else dist_dict[b]
                    for b in range(b_num)
                }
                is_break = True
                break
        if is_break == False:
            b_set_list.append({u, v})
            copy_dist_dict = dict(dist_dict)
            for b, ad_tup in copy_dist_dict.items():
                if ad_tup[0] == 0:
                    continue
                else: 
                    dist_min_u = cal_dist_sq(b_list[u], b_list[b])
                    dist_min_v = cal_dist_sq(b_list[v], b_list[b])
                    dist_min = min(
                        dist_min_u,
                        dist_min_v,
                        ad_tup[0]
                    )
                    if dist_min == dist_min_u:
                        dist_dict[b] = (dist_min_u, u)
                    elif dist_min == dist_min_v:
                        dist_dict[b] = (dist_min_v, v)
                    else: 
                        continue

    while max([ad_tup[0] for ad_tup in dist_dict.values()]) != 0:
        v = find_min_b(dist_dict)
        c_list.append(dist_dict[v][0])
        
        for b_set in b_set_list:
            if dist_dict[v][1] in b_set:
                b_set.add(v)
                
        dist_dict = {b: (
                cal_dist_sq(b_list[v], b_list[b]),
                v
            ) if cal_dist_sq(b_list[v], b_list[b]) < dist_dict[b][0]
            else dist_dict[b]
            for b in range(b_num)
        }
    g_dist_dict = {i_tup : cal_dist_g(
            b_set_list[i_tup[0]], 
            b_set_list[i_tup[1]],
            b_list
        ) 
        for i_tup 
        in combinations(range(len(b_set_list)),2)
    }
    print(
        sum(map(sqrt,c_list)) 
        + sum(map(sqrt,get_min_dist_list(len(b_set_list), g_dist_dict)))
    )
    

# 0부터 v_num -1 번째 노드까지 lo 이상 hi 이하의 가중치의 간선들만 사용하여
# 연결할 수 있는지 확인하는 함수

def has_bounded_path(lo, hi, v_num, sorted_e):
    if v_num == 1:
        return True
    elif sorted_e:
        return False
    else:
        l_i, h_i = 0,0
        visited = {i: True if i==0 else False for i in range(v_num)}
        q = [0]
        for i in range(len(sorted_e)):
            if sorted_e[i][0] < lo:
                l_i = i + 1
            if sorted_e[i][0] =< hi:
                h_i = i
        while q:
            v = q.pop(0)
            for e in sorted_e[l_i, h_i+1]:
                if e[1][0] == v:
                    u == e[1][1]
                elif e[1][1] == v:
                    u == e[1][0]
                else:
                    continue
                if visited[u]:
                    continue
                else:
                    visited[u] = True
                    q.append(u)
        return visited[v_num-1]

for _ in range(int(raw_input())):
    v_num, e_num = tuple(map(int,raw_input().strip().split(" ")))
    sorted_e = []
    for _ in range(e_num):
        v, u, weight = tuple(map(int,raw_input().strip().split(" ")))
        sorted_e.append((weight, (v, u)))
        sorted_e.sort()
    
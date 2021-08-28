import heapq, sys 

for _ in range(int(sys.stdin.readline().strip())):
    v, e, n, m = tuple(map(int,sys.stdin.readline().strip().split(" ")))
    
    ad_dict = [[] for _ in range(v+1)]
    for _ in range(e):
        a, b, t = tuple(map(int,sys.stdin.readline().strip().split(" ")))
        ad_dict[a].append((t, b))
        ad_dict[b].append((t, a))

    fire_positions = list(map(int, sys.stdin.readline().strip().split(" ")))
    fire_stations = list(map(int, sys.stdin.readline().strip().split(" ")))

    dist_dict = [float("inf") if not i in fire_stations else 0 for i in range(v+1)]
    priority_q = [(0,i) for i in range(v+1) if i in fire_stations]

    while priority_q:
        dist, pos = heapq.heappop(priority_q)
        
        if dist_dict[pos] < dist:
            continue

        for pos_tup in ad_dict[pos]:
            dist_sum = pos_tup[0] + dist
            if dist_dict[pos_tup[1]] > dist_sum:
                dist_dict[pos_tup[1]] = dist_sum	
                heapq.heappush(priority_q, (dist_sum, pos_tup[1]))
    print(sum([dist_dict[i] for i in range(v+1) if i in fire_positions]))

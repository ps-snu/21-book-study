import heapq, sys 

for _ in range(int(sys.stdin.readline().strip())):
	com_num, line_num = tuple(map(int,sys.stdin.readline().strip().split(" ")))
	noise_dict = [1,] + [float("inf"),] * (com_num - 1)
	priority_q = [(1,0)]
	ad_dict = [[] for _ in range(com_num)]
	for _ in range(line_num):
		com1, com2, noise = tuple(sys.stdin.readline().strip().split(" "))
		com1, com2, noise = int(com1), int(com2), float(noise)
		ad_dict[com1].append((noise, com2))
		ad_dict[com2].append((noise, com1))

	while priority_q:
		noise, com = heapq.heappop(priority_q)
		if noise_dict[com] < noise:
			continue

		for com_tup in ad_dict[com]:
			noise_prod = com_tup[0] * noise
			if noise_dict[com_tup[1]] > noise_prod:
				noise_dict[com_tup[1]] = noise_prod	
				heapq.heappush(priority_q, (noise_prod, com_tup[1]))
	print(noise_dict[-1])
			
import heapq

test_num = int(input().strip())
for _ in range(test_num):
	ad_dict = dict()
	com_num, line_num = tuple(map(int,input().strip().split(" ")))
	dist_dict = {i:float("inf") for i in range(com_num)}
	priority_q = []
	for _ in range(line_num):
		com1, com2, noise = tuple(input().strip().split(" "))
		com1, com2, noise = int(com1), int(com2), float(noise)
		if com1 in ad_dict:
			ad_dict[com1].append((com2,noise))
		else:
			ad_dict[com1] = [(com2,noise)]
		if com2 in ad_dict:
			ad_dict[com2].append((com1,noise))
		else:
			ad_dict[com2] = [(com1,noise)]
	
	for com_tup in ad_dict[0]:
		com, noise = com_tup
		dist_dict[com] = noise

	while 
			
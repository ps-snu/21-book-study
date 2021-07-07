

num = int(input())
for i in range(num):
    stuff_num, bag_volume = tuple(map(int, input().strip().split(" ")))
    volume_dict = dict()
    degree_dict = dict()
    ratio_dict = dict()
    for j in range(int(stuff_num)):
        stuff_name, stuff_volume, stuff_degree = tuple(input().strip().split(" "))
        volume_dict[stuff_name] = int(stuff_volume)
        degree_dict[stuff_name] = int(stuff_degree)
        ratio = int(stuff_degree)/int(stuff_volume)
        if ratio in ratio_dict:
            for i in range(len(ratio_dict[ratio])):
                if ratio_dict[ratio][i] < stuff_volume:
                    ratio_dict[ratio].insert(i,stuff_name)
        else:
            ratio_dict[ratio] = [stuff_name,]
    
    ratio_list = list(ratio_dict.keys())
    ratio_list.sort(reverse = True)
    stuff_list = list()
    desperate_degree = 0
    for ratio in ratio_list:
        for stuff in ratio_dict[ratio]: 
            if volume_dict[stuff] < bag_volume:
                stuff_list.append(stuff)
                desperate_degree += degree_dict[stuff]
                bag_volume -= volume_dict[stuff]


    print(desperate_degree, len(stuff_list))
    for key in stuff_list:
        print(key)
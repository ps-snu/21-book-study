def max_degree(stuff_num: int, bag_volume: int, volume_dict: dict, degree_dict: dict) ->tuple:
    if bag_volume < 0:
        return (dict(),dict())
    if stuff_num == 1:
        if list(volume_dict.values())[0] > bag_volume :
            return (dict(), dict())
        else:
            return (dict(volume_dict), dict(degree_dict))
    else: 
        stuff_name = list(volume_dict.keys())[0]
        copy_volume_dict, copy_degree_dict = dict(volume_dict), dict(degree_dict)
        stuff_volume, stuff_degree = copy_volume_dict.pop(stuff_name), copy_degree_dict.pop(stuff_name)
        max_volume_dict, max_degree_dict = max_degree(stuff_num - 1, bag_volume, copy_volume_dict, copy_degree_dict)
        
        if stuff_volume > bag_volume:
            return (max_volume_dict, max_degree_dict)
        
        compare_volume_dict, compare_degree_dict = max_degree(stuff_num - 1, bag_volume - stuff_volume, copy_volume_dict, copy_degree_dict)
        
        if sum(max_degree_dict.values()) > sum(compare_degree_dict.values()) + stuff_degree:
            return (max_volume_dict, max_degree_dict)
        else:
            compare_volume_dict[stuff_name] = stuff_volume
            compare_degree_dict[stuff_name] = stuff_degree
            return (compare_volume_dict, compare_degree_dict)

num = int(input())
for i in range(num):
    stuff_num, bag_volume = tuple(map(int, input().strip().split(" ")))
    volume_dict = dict()
    degree_dict = dict()
    for j in range(int(stuff_num)):
        stuff_name, stuff_volume, stuff_degree = tuple(input().strip().split(" "))
        volume_dict[stuff_name] = int(stuff_volume)
        degree_dict[stuff_name] = int(stuff_degree)

    res_volume_dict, res_degree_dict = max_degree(stuff_num, bag_volume, volume_dict, degree_dict)

    print(sum(res_degree_dict.values()), len(res_degree_dict))
    for key in res_degree_dict:
        print(key)
    
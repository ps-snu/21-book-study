is_list = [] 
test_case_num = int(input().strip())
for i in range(test_case_num):
    sequence_size, lexicographical_order = tuple(map(int,input().rstrip().split(" ")))
    sequence = list(map(int,input().rstrip().split(" ")))
    is_list = []
    max_len = 0
    is_stick = False
    
    for e in sequence:
        is_stick = False
            
        for increasing_subsequence in is_list:
            if increasing_subsequence[-1] < e:
                is_list.insert(
                    is_list.index(increasing_subsequence) + 1, 
                    increasing_subsequence + [e,]
                )
                is_stick = True

        if not is_stick:
            is_list.insert(0,[e,])

    max_len = max(*map(len,is_list))
    print(max_len)
    for increasing_subsequence in is_list:
        if len(increasing_subsequence) == max_len:
            print(increasing_subsequence)
    # print(
    #     *[
    #         increasing_subsequence for increasing_subsequence in is_list if len(increasing_subsequence) == max_len
    #     ][lexicographical_order - 1]
    # )

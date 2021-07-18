# sequence: 매 시행에서 정수들의 list
sequence = []
# max_len_cnt_list: i번째 원소가 sequence의 i번째 원소로 시작하는 
# IS(increasing subsequence) 중에서 제일 긴 IS의 길이와 그 갯수 튜플  
max_len_cnt_list = []
def get_klis(k: int, i:int, length: int) -> list:
    global sequence
    global max_len_cnt_list
    if max_len_cnt_list[i][1] < k:
        return get_klis( 
            k - max_len_cnt_list[i][1],
            sequence.index(
                min(
                    [
                        sequence[j] 
                        for j
                        in range(len(sequence)) 
                        if max_len_cnt_list[j][0] == length 
                        and sequence[i] < sequence[j] 
                    ]
                )
            ),
            length
        )
    else: 
        if length == 1:
            return [sequence[i]]
        return [sequence[i]] + get_klis(
            k,
            sequence.index(
                min(
                    [
                        sequence[j] 
                        for j
                        in range(i,len(sequence)) 
                        if max_len_cnt_list[j][0] == length - 1 
                        and sequence[i] < sequence[j] 
                    ]
                )
            ),
            length - 1
        )

test_case_num = int(input().strip())
for i in range(test_case_num):
    sequence_size, lexicographical_order = tuple(map(int,input().rstrip().split(" ")))
    sequence = list(map(int,input().rstrip().split(" ")))
    partial_max_len = 0
    max_len = 1
    cnt = 0
    max_len_cnt_list = [(0,0,[]),] * len(sequence)
        
    for i in range(len(sequence)):
        large_start_list = [max_len_cnt_list[j] for j in range(len(sequence)-i, len(sequence)) if sequence[len(sequence) - i - 1] < sequence[j]]
        if len(large_start_list) > 0:
            partial_max_len = max(
                [
                    len_cnt_tup[0] 
                    for len_cnt_tup 
                    in large_start_list
                ]   
            )
            cnt = sum([max_len_tup[1] for max_len_tup in large_start_list if max_len_tup[0] == partial_max_len])
            max_len_cnt_list[len(sequence) - i - 1] = (partial_max_len + 1, cnt)
            if partial_max_len == max_len:
                max_len += 1
        else:
            max_len_cnt_list[len(sequence) - i - 1] = (1, 1)
            
    print(max_len)
    print(
        *get_klis(
            lexicographical_order,
            sequence.index(
                min(
                    [
                        sequence[i] 
                        for i 
                        in range(len(sequence)) 
                        if max_len_cnt_list[i][0] == max_len
                    ]
                )
            ),
            max_len
        )
    )


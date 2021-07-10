word_num, test_num = tuple(
    map(
        int,
        input().rstrip().split(" ")
    )
)

word_list = input().rstrip().split(" ")

first_prob = list(
    map(
        float,
        input().rstrip().split(" ")
    )
)


next_prob = []
miss_prob = []

# 각 자리에 단어가 나올 확률의 2d array
# word_prob[i][j]: i 번째 자리에 word_list의 J번째 단어가 나올 확률
word_prob = [first_prob,]

for i in range(word_num):
    next_prob.append(
        list(
            map(
                float,
                input().rstrip().split(" ")
            )
        )
    )

for i in range(word_num):
    miss_prob.append(
        list(
            map(
                float,
                input().rstrip().split(" ")
            )
        )
    )

def expand_word_prob():
    word_prob.append(
        [
            sum(
                [
                    p*q 
                    for p,q in zip(
                        word_prob[-1],
                        [
                            prob_list[i] 
                            for prob_list in next_prob 
                        ]
                    )
                ]
            ) 
            for i in range(len(next_prob[0]))
        ]
    )

for i in range(test_num):
    input_list = input().rstrip().split(" ")
    test_word_num = int(input_list[0])
    test_word_list = input_list[1:]
    res_list = ['I',]

    if test_word_num > len(word_prob):
        for i in range(test_word_num - len(word_prob)):
            expand_word_prob()
    
    for j in range(1, test_word_num):
        word = test_word_list[j]
        word_index = word_list.index(word)
        print(word_index, [
                    prob_list[word_index] 
                    for prob_list in miss_prob 
                ])
        conditional_prob_list = [
            p*q 
            for p,q in zip(
                word_prob[j],
                [
                    prob_list[word_index] 
                    for prob_list in miss_prob 
                ]
            )
        ]
        print(conditional_prob_list)
        max_index = conditional_prob_list.index(max(conditional_prob_list))
        res_list.append(word_list[max_index])
    print(" ".join(res_list))



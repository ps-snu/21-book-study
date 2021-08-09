test_num = int(input().strip())
def sum(list)->int:
    res = 0
    for e in list:
        res += e
    return res 

for _ in range(test_num):
    word_num = int(input().strip())
    char_list = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
    start_char = dict()
    for c in char_list:
        start_char[c] = []
    end_char  = dict() 
    for c in char_list:
        end_char[c] = []
    word_chain = []

    start_word = ""
    end_word = ""

    for _ in range(word_num):
        word = input().strip()
        start_char[word[0]].append(word)
        end_char[word[-1]].append(word)
    is_possible = True
    for char in start_char:
        len_diff = len(start_char[char]) - len(end_char[char])
        if len_diff == 1:
            if start_word == "":
                start_word = start_char[char][0]
            else:
                is_possible = False
                break
        elif len_diff == -1:
            if end_word == "":
                end_word = end_char[char][0]
            else:
                is_possible = False
                break
        elif len_diff == 0:
            pass
        else:
            is_possible = False
            break
    if not is_possible:
        print("IMPOSSIBLE")
    else:
        if start_word == "":
            for char in start_char:
                if len(start_char[char]) != 0:
                    start_word = start_char[char][0]
                    break
            
        start_char[start_word[0]].remove(start_word)
        end_char[start_word[-1]].remove(start_word)

        word_chain.append(start_word)
        cur_word = start_word
        while sum(map(len,start_char.values())) != 0:
            cur_word = start_char[cur_word[-1]].pop(0)
            end_char[cur_word[-1]].remove(cur_word)
            word_chain.append(cur_word)
        print(' '.join(word_chain))
        
    
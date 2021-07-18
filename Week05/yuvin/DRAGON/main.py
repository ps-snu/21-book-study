import math
test_case_num = int(input().strip())
def transpose(dragon_curve_str:str) -> str:
    res_str = ""
    for c in dragon_curve_str:
        if c == 'X':
            res_str += "X+YF"
        elif c == 'Y':
            res_str += "FX-Y"
        else:
            res_str += c
    return res_str

def get_last_len(c: str, n: int) -> int:
    if c == "X" or c == "Y":
        return 3 * int(math.pow(2,n)) - 2
    else:
        return 1

for i in range(test_case_num):
    generation_num, start_pos, length = tuple(map(int,input().rstrip().split(" ")))
    dragon_curve = "FX"
    #X,Y,F,+,-
    cnt_sum = 0
    for j in range(generation_num):
        dragon_curve = transpose(dragon_curve)
        c = dragon_curve[0]
        k = 0
        while cnt_sum + get_last_len(c,generation_num - j - 1) < start_pos:
            k += 1
            dragon_curve = dragon_curve[1:]
            cnt_sum += get_last_len(c,generation_num - j - 1)
            c = dragon_curve[0]

        if len(dragon_curve) > length:
            dragon_curve = dragon_curve[:length]

    print(dragon_curve[start_pos-cnt_sum -1 : start_pos - cnt_sum + length - 1])

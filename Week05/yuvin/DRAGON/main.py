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
for i in range(test_case_num):
    generation_num, start_pos, length = tuple(map(int,input().rstrip().split(" ")))

    dragon_curve = (0,"FX")
    res_str = dragon_curve[2]
    for i in range(generation_num):
        dragon_curve = (dragon_curve[0], transpose(res_str))

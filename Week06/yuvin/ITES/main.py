import math

test_case_num = int(input().strip())
for i in range(test_case_num):
    k, n = tuple(map(int,input().strip().split(" ")))
    a = [1983]
    b = [1984]  
    res = 0
    sum_res = 1984
    for j in range(n):
        if sum_res == k:
            res +=1
        
        a.append((a[-1] * 214013 + 2531011) % int(math.pow(2,32)))
        b.append(a[-1] % 10000 + 1)
        sum_res += b[-1]
        if sum_res > k:
            while sum_res > k and len(b) > 1:
                sum_res -= b.pop(0)
                a.pop(0)
    print(res)
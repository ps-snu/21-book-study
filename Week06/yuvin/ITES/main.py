import math

a = [1983]
b = [1984]
test_case_num = int(input().strip())
for i in range(test_case_num):
    k, n = tuple(map(int,input().strip().split(" ")))
    res = 0
    if n > len(a):
        for i in range(len(a),n+1):
            a.append((a[-1] * 214013 + 2531011) % int(math.pow(2,32)))
            b.append(a[-1] % 10000 + 1)
    for i in range(n):
        sum_res = b[i] 
        j = i + 1
        while sum_res < k:
            if j == n:
                break

            sum_res += b[j]
            j += 1
            
        if sum_res == k:
            res += 1
    print(res)
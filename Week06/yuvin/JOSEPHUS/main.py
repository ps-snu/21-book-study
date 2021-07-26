def transpose(a,n,k):
    if a + k > n:
        return (a + k) % n + 1
    else:
        return a + k
    
def josephus(n: int, k: int):
    if n == 2:
        return 1, 2
    else:
        a, b = josephus(n-1, k)
        return transpose(a,n,k), transpose(b,n,k)

res_list = [(1,2)]

test_case_num = int(input().strip())
for i in range(test_case_num):
    n, k = tuple(map(int,input().strip().split(" ")))
    res_list = [(1,2)]
    for j in range(3,n+1):
        res_list.append((transpose(res_list[-1][0],j,k),transpose(res_list[-1][1],j,k)))
    res = res_list[-1]
    if res[0] < res[1]:
        print(*res)
    else:
        print(*reversed(res))

def transpose(a,n,k):
    return (a + k-2) % (n-1) + 2

test_case_num = int(input().strip())
for i in range(test_case_num):
    n, k = tuple(map(int,input().strip().split(" ")))
    res = (1,2)
    for j in range(3,n+1):
        res = (transpose(res[0],j,k),transpose(res[1],j,k))

    if res[0] < res[1]:
        print(*res)
    else:
        print(*reversed(res))

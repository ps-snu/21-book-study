def transpose(a,n,k):
<<<<<<< HEAD
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
=======
    return (a + k-2) % (n-1) + 2
>>>>>>> 69460cbdeda3ffe01136efc46f50f11c4cc7c093

test_case_num = int(input().strip())
for i in range(test_case_num):
    n, k = tuple(map(int,input().strip().split(" ")))
<<<<<<< HEAD
    res_list = [(1,2)]
=======
    res = (1,2)
>>>>>>> 69460cbdeda3ffe01136efc46f50f11c4cc7c093
    for j in range(3,n+1):
        res = (transpose(res[0],j,k),transpose(res[1],j,k))

    if res[0] < res[1]:
        print(*res)
    else:
        print(*reversed(res))

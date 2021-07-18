comb_array = [[1,],[1,1,],[1,2,1,]]

def comb(n: int, m: int) -> int:
    global comb_array
    if not len(comb_array) > n:
        comb_array.append([1,] + [comb(n-1, i) + comb(n-1, i+1) for i in range(n-1)] + [1,])

    return comb_array[n][m]

def morse(n: int, m: int, k: int) -> str:
    if k == 1:
        return "-" * n + "o" * m
    elif comb(n+m-1,m) < k:
        return "o" + morse(n, m-1, k - comb(n+m-1,m))
    else:
        return "-" + morse(n-1, m, k)

test_num = int(input().rstrip())

for test in range(test_num):
    n, m, k = tuple(map(int,input().rstrip().split(" ")))
    print(morse(n,m,k))
    

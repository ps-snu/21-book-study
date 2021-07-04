polyomino_list = [[1],[1,1]] 
def polyomino(n:int):
    if n > len(polyomino_list):
        res_list = [0,]*(n-1) + [1,]
        for i in range(1,n):
            # n-i개의 블럭이 첫번째 행에 존재 할때의 가지수
            # res_list에서 (0번째부터 시작) n-i-1 번째 값 
            # 두번째 행부터 i 개의 블럭이 쌓여야 한다.
            for j in range(i):
                res_list[n-i-1] += (n-i+j) * polyomino(i)[i-1][j]
        polyomino_list.append(res_list)
        return polyomino_list
    else:
        return polyomino_list 
    
num = int(input())
for i in range(num):
    val = int(input().rstrip())
    print(sum(polyomino(val)[val-1])%10000000)
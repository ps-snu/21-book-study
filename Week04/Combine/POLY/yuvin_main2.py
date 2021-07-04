poly_list = [1,2,6,19]

def polyomino(n:int)->list:
    if n > len(poly_list):
        bn_3 = polyomino(n-3)[n-4]
        bn_2 = polyomino(n-2)[n-3]
        bn_1 = polyomino(n-1)[n-2] 
        res = 5 * bn_1 - 7 * bn_2 + 4 * bn_3
        poly_list.append(res)
        return poly_list
    else:
        return poly_list
    
num = int(input())
for i in range(num):
    val = int(input().rstrip())
    print(str(polyomino(val)[val-1]%10000000))
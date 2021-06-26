tile_dic = {1:1,2:2}
def tiling(n: int)->int:
    if n < 1:
        return 0
    elif n in tile_dic:
        return tile_dic[n]
    else:
        a = tiling(n-2) 
        b = tiling(n-1)
        res = a + b
        tile_dic[n] = res
        return res
        
asym_tile_dic = {3:2}
def asym_tiling(n:int)->int:
    if n < 3:
        return 0
    elif n in asym_tile_dic:
        return asym_tile_dic[n]
    else:
        a = asym_tiling(n-4)
        b = 2 * tiling(n-3)
        c = asym_tiling(n-2)
        res = a + b + c
        asym_tile_dic[n] = res
        return res 
    
num = int(input())
for i in range(num):
    print(asym_tiling(int(input().rstrip()))%1000000007)
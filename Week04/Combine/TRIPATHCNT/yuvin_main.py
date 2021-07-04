num = int(input())
for i in range(num):
    size = int(input())
    res_list = list()
    for i in range(size):
        tri_row = list(map(int,input().rstrip().split(" ")))
        if i == 0:
            res_list.append((tri_row[0],1))
        else:
            res_list =[a if a[0]>b[0] else b if a[0]<b[0] else (a[0],a[1]+b[1]) for a,b in zip([(t + r[0],r[1]) for t,r in zip(tri_row,res_list+[(0,1)])],[(t + r[0],r[1]) for t,r in zip(tri_row,[(0,1)]+res_list)])]
    print(str(sum([a[1] if a[0] == max([b[0] for b in res_list]) else 0 for a in res_list])))



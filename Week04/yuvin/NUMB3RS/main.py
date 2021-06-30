
def list_dot(a,b)->float:
    return sum([x*y for x,y in zip(a,b)])

def matrix_dot(a, b):
    return [
        [
            list_dot(
                a[i],
                [
                    b[k][j] for k in range(len(b))
                ]
            ) 
            for j in range(len(b[0]))
        ] for i in range(len(a))
    ]


def dunibal(days:int,prison_position:int,marcov_matrix):
    q_list = [marcov_matrix[prison_position],]
    for _ in range(days-1):
        q_list = matrix_dot(q_list,marcov_matrix)
    return q_list[0]

num = int(input())
for i in range(num):
    n, d, p = tuple(
        map(
            int,
            input().rstrip().split(" ")
        )
    )
    villages = []
    for _ in range(n):
        villages.append(
            list(
                map(
                    int,
                    input().rstrip().split(" ")
                )
            )
        )
    t = int(input())
    target_list = list(
        map(
            int,
            input().rstrip().split(" ")
        )
    )
    villages = [
        [   
            q/sum(q_list) for q in q_list
        ] for q_list in villages
    ]
    res_q_list = dunibal(d,p,villages)
    print(
        *map(
            str,
            [   
                res_q_list[target] for target in target_list
            ]
        )
    )
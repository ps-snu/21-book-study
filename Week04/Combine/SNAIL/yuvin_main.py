# def prob(n:int, m:int)->float:
#     if m == 1:
#         if n == 1:
#             return 0.25
#         elif n == 2:
#             return 0.75
#         else:
#             return 0
#     else:
#         return 0.25 * prob(n-1,m-1) + 0.75 * prob(n-2,m-1)

# def escape_prob(n:int, m:int)->float:
#     if m == 1:
#         if n < 2:
#             return 1
#         elif n == 2:
#             return 0.75
#         else:
#             return 0
#     else:
#         return escape_prob(n-1,m-1)+0.75*prob(n-2,m-1)
    
# def escape_prob2(n:int, m:int)->float:
#     if m == 1:
#         if n < 2:
#             return 1
#         elif n == 2:
#             return 0.75
#         else:
#             return 0
#     else:
#         return 0.25 * escape_prob2(n-1,m-1) + 0.75 * escape_prob2(n-2,m-1)

prob_array = [[1,],]
def escape_prob(n:int, m:int)->float:
    if m > len(prob_array[0]):
        for i in range(len(prob_array)):
            if i < 2:
                prob_array[i] += [1,] * (m-len(prob_array[i]))
            else:
                prob_array[i] += [0.25*prob_array[i-1][j-1]+0.75*prob_array[i-2][j-1] for j in range(len(prob_array[i]),m)]
    for i in range(len(prob_array),n):
        # 2미터를 j(1,..,m)일 안에 탈출할 확률 
        if i == 1:
            prob_array.append([0.75,] + [1,] * max(len(prob_array[0]),m-1))
        else:
            prob_array.append([0 if j == 0 else 0.25*prob_array[i-1][j-1]+0.75*prob_array[i-2][j-1] for j in range(max(m,len(prob_array[0])))])
    return prob_array[n-1][m-1]

num = int(input())
for i in range(num):
    print(escape_prob(*map(int,input().rstrip().split(" "))))
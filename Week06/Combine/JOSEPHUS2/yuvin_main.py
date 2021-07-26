class Node():
    def __init__(self,n:int):
        self.val = n
    
    def get_val(self):
        return self.val
    
    def set_next(self,next_node):
        self.next = next_node

    def get_next(self):
        return self.next

test_case_num = int(input().strip())
for i in range(test_case_num):
    n, k = tuple(map(int,input().strip().split(" ")))

    first_node = pre_node = Node(1)
    for j in range(1,n):
        cur_node = Node(j+1)
        pre_node.set_next(cur_node)
        pre_node = cur_node

    cur_node.set_next(first_node)

    cur_node = first_node

    for j in range(n-2):
        pre_node.set_next(cur_node.get_next())
        
        cur_node = cur_node.get_next()
        for l in range(k-1):
            pre_node = cur_node
            cur_node = cur_node.get_next()

    if cur_node.get_val() > pre_node.get_val():
        print(pre_node.get_val(), cur_node.get_val())
    else:
        print(cur_node.get_val(), pre_node.get_val())

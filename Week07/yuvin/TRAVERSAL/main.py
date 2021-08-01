class Tree_node():
    def __init__(self, node_val: int):
        self.val = node_val
        self.r = None
        self.l = None
    
    def set_val(self, node_val: int):
        self.val = node_val
        
    def set_l(self, node_val: int):
        self.l = Tree_node(node_val)
    
    def set_r(self, node_val: int):
        self.r = Tree_node(node_val)
    
    def get_val(self):
        return self.val
    
    def get_l(self):
        return self.l 
    
    def get_r(self):
        return self.r
    
def print_post_order(tr: Tree_node):
    if tr == None:
        return
    print_post_order(tr.get_l())
    print_post_order(tr.get_r())
    print(tr.get_val(), end = " ")

def recursive_set(pre_order, in_order, cur_tr):
    # assert len(pre_order) == len(in_order), f"pre_order : {pre_order}, in_order : {in_order} must be same in length"
    if len(pre_order) == len(in_order) == 0:
        return 
    
    root_val = pre_order[0]
    cur_tr.set_val(root_val)
    
    #left node 가 있는 경우
    if in_order.index(root_val) != 0:
        left_in_order = in_order[:in_order.index(root_val)]
        left_pre_order = pre_order[1:1 + len(left_in_order)]
        cur_tr.set_l(Tree_node(0))
        recursive_set(left_pre_order,left_in_order,cur_tr.get_l())
        
    # right node 가 있는 경우 
    if in_order.index(root_val) != len(in_order) - 1:
        right_in_order = in_order[in_order.index(root_val) + 1:]
        right_pre_order = pre_order[-len(right_in_order):]
        cur_tr.set_r(Tree_node(0))
        recursive_set(right_pre_order,right_in_order,cur_tr.get_r())

test_num = int(input().strip())

for i in range(test_num):
    node_num = int(input().strip())
    pre_order = list(map(int,input().strip().split(" ")))
    in_order = list(map(int,input().strip().split(" ")))
    root_tr = Tree_node(0)
    recursive_set(pre_order, in_order, root_tr)
    print_post_order(root_tr)
    print("")
        
                
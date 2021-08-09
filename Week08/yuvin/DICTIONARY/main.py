from typing import List,Tuple

class OrderNode():
    def __init__(self):
        return

class OrderNode():
    def __init__(self,char):
        self.char = char
        self.next_nodes = []

    def get_char(self):
        return self.char

    def set_next_node(self, node):
        self.next_nodes.append(node)
    
    def get_next_nodes(self):
        return self.next_nodes

    def find_node(self,char) -> Tuple[bool,OrderNode]:
        if char == self.char:
            return True, self
        elif len(self.next_nodes) == 0:
            return False, None
        else:            
            for next_node in self.next_nodes:  
                result = next_node.find_node(char)
                if result[0]:
                    return result
            return False, None

    def delete_node(self,char):
        if len(self.next_nodes) == 0:
            return 
        else:
            for next_node in self.next_nodes:
                if next_node.get_char() == char:
                    self.next_nodes.remove(next_node)
                    return
                else:
                    next_node.delete_node(char)
            return
def recursive_merge(root,pre_node,next_node):
    if root == pre_node:
        return 
    else: 
        if next_node in root.get_next_nodes():
            root.get_next_nodes().remove(next_node)
        else:
            for node in root.get_next_nodes():
                if node.find_node(pre_node)[0]:
                    recursive_merge(node,pre_node,next_node)

def find_order(pre_word: str, next_word: str, roots: List[OrderNode], chars: set) -> bool:
    print(pre_word,next_word)
    if len(pre_word) == 0:
        return True
    elif len(next_word) == 0:
        return False
    elif pre_word[0] == next_word[0]:
        return find_order(pre_word[1:], next_word[1:], roots, chars)
    else:
        pre_char = pre_word[0]
        next_char = next_word[0]
        is_pre = pre_char in chars
        is_next = next_char in chars
        chars.difference_update({pre_char,next_char})

        if not (is_pre or is_next):
            new_root = OrderNode(pre_char)
            new_root.set_next_node(OrderNode(next_char))
            roots.append(new_root)
            return True
        elif not is_next:
            for root in roots:
                contain_pre_char, pre_char_node = root.find_node(pre_char)
                if contain_pre_char:
                    pre_char_node.set_next_node(OrderNode(next_char))
            return True
        
        elif not is_pre:
            for root in roots:
                contain_next_char, next_char_node = root.find_node(next_char)
                if contain_next_char:
                    new_root = OrderNode(pre_char)
                    new_root.set_next_node(next_char_node)
                    roots.append(new_root)
            return True
        else:
            pre_char_node, pre_char_root = None, None
            next_char_node, next_char_root = None, None

            for root in roots:
                pre_res = root.find_node(pre_char)
                next_res = root.find_node(next_char)
                if pre_res[0]:
                    pre_char_node = pre_res[1]
                if next_res[0]:
                    next_char_node = next_res[1]

                if pre_res[0] and next_res[0]:
                    pre_char_node = pre_res[1]
                    next_char_node = next_res[1]
                    pre_next_res = pre_char_node.find_node(next_char)
                    next_pre_res = next_char_node.find_node(pre_char)
                    if pre_next_res[0]:
                        return True
                    elif next_pre_res[0]:
                        return False
                    else:
                        recursive_merge(root,pre_char_node,next_char_node)
                        pre_char_node.set_next_node(next_char_node)
                        return True
                else:
                    pre_char_node.set_next_node(next_char_node)
                    return True

def print_roots(roots:List[OrderNode]):
    print("print")
    char_dict = {chr(o):True for o in range(ord("a"),ord("z")+1)}
    queue = roots
    while len(queue) != 0:
        node = queue.pop(0)
        print(node.get_char(), end = " ")
        for n in node.get_next_nodes():
            if char_dict[n.get_char()]:
                queue.append(n)
    print("end")
test_num = int(input().strip())

for _ in range(test_num):
    word_num = int(input().strip())
    word_list = [
        input().strip() 
        for _ 
        in range(word_num)
    ]
    chars = {chr(o) for o in range(ord("a"),ord("z")+1)}
    roots = [OrderNode(word_list[0][0])]
    is_possible = True
    for pre_word, next_word in zip(word_list[:-1],word_list[1:]):
        if not find_order(pre_word, next_word, roots, chars):
            is_possible = False
            continue
    
    if not is_possible:
        print("IMPOSSIBLE")
    else:
        print_roots(roots)
    queue = []
    
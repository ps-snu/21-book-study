class Fortress():
    def __init__(self,x,y,r):
        self.x = x
        self.y = y
        self.r = r
        self.inner_fortresses = set()
        
    def get_x(self):
        return self.x
    
    def get_y(self):
        return self.y
    
    def get_r(self):
        return self.r
    
    def get_inner_fortresses(self):
        return self.inner_fortresses
    
    def add_inner_fortress(self, new_fortress):
        if len(self.inner_fortresses) != 0:
            for fortress in self.inner_fortresses:
                # 성벽을 포함하는 경우
                if (fortress.x - new_fortress.x) ** 2 + (fortress.y - new_fortress.y) ** 2 < (fortress.r - new_fortress.r) ** 2:
                    if new_fortress.r > fortress.r:
                        self.inner_fortresses.remove(fortress)
                        new_fortress.add_inner_fortress(fortress)
                        self.inner_fortresses.add(new_fortress)
                    else:
                        fortress.add_inner_fortress(new_fortress)
                    return
        self.inner_fortresses.add(new_fortress)
        return

def print_fortress(f:Fortress):
    print(f"x:{f.get_x()}, y:{f.get_y()}, r:{f.get_r()}")
    if len(f.get_inner_fortresses()) != 0:
        for sub_f in f.get_inner_fortresses():
            print_fortress(sub_f)
            print("")
        
        

def get_longest_term(fortress: Fortress) -> int:
    if len(fortress.get_inner_fortresses()) == 0:
        return 0
    else:
        longest_list = list(map(get_longest_term,fortress.get_inner_fortresses()))
        if len(longest_list) == 1:
            return longest_list[0] + 1
        else:
            return max(*longest_list) + 1 
    
test_num = int(input().strip())
for i in range(test_num):
    fortress_num = int(input().strip())
    outer_fortress = None
    for j in range(fortress_num):
        x,y,r = tuple(map(int,input().strip().split(" ")))
        if j == 0:
            outer_fortress = Fortress(x,y,r)
        else:
            outer_fortress.add_inner_fortress(Fortress(x,y,r))
    distance_list = list(map(get_longest_term,outer_fortress.get_inner_fortresses()))
    print_fortress(outer_fortress)
    longest_distance = 0
    for j in range(2):
        if len(distance_list) > 1:
            max_distance = max(*distance_list)
            longest_distance += (max_distance + 1)
            distance_list.remove(max_distance)
        elif len(distance_list) == 1:
            longest_distance += (distance_list.pop(0) + 1)
    print(longest_distance)
    
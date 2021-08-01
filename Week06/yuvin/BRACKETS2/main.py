def is_right(brackets: str) -> bool:
    brackets_stack = []
    for b in brackets:
        if b == "(" or b == "{" or b == "[":
            brackets_stack.append(b)
        else:
            if len(brackets_stack) == 0:
                return False
            c = brackets_stack.pop(len(brackets_stack) - 1)
            if c == "(" and b == ")":
                pass
            elif c == "{" and b == "}":
                pass
            elif c == "[" and b == "]":
                pass
            else:
                return False
    if len(brackets_stack) == 0:
        return True
    else:
        return False
    
test_case_num = int(input().strip())
for i in range(test_case_num):
    brackets = input().strip()
    print("YES" if is_right(brackets) else "NO")
    
    
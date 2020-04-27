tc = int(input())

for i in range(tc):
    stack = []
    ps = input()
    isVPS = True

    for j in range(len(ps)):
        if ps[j] == '(':
            stack.append('(')
        else:
            if len(stack) == 0:
                isVPS = False
                break
            stack.pop()

    if len(stack) != 0:
        isVPS = False

    if isVPS:
        print("YES")
    else:
        print("NO")
import sys

stack = []


n = int(sys.stdin.readline())

for i in range(n):
    a = list(map(str, sys.stdin.readline().split()))

    if(a[0] == 'push'):
        stack.append(int(a[1]))
    elif(a[0] == 'pop'):
        if(not stack):
            print(-1)
        else:
            print(stack.pop())
    elif(a[0] == 'size'):
        print(len(stack))
    elif(a[0] == 'top'):
        if(not stack):
            print(-1)
        else:
            print(stack[-1])
    else:
        if(not stack):
            print(1)
        else:
            print(0)

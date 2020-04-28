import sys

k = int(input())
stack = []

for _ in range(k):
    ip = str(sys.stdin.readline().split()[0])

    if ip == '0':
        stack.pop()
    else:
        stack.append(int(ip))


print(sum(stack))
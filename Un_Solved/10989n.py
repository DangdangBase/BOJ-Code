import sys

a = int(sys.stdin.readline())
b = []

for i in range(a):
    b.append(int(sys.stdin.readline()))

b.sort()

for k in b:
    print(k)

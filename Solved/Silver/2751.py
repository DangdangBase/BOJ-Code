import sys

a =  int(input())
b = []
for i in range(a):
    b.append(int(sys.stdin.readline()))

b.sort()

for k in b:
    print(k)
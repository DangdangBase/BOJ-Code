import sys

a = int(sys.stdin.readline())
num = []

for i in range(a):
    num.append(int(sys.stdin.readline()))

num.sort()

for i in num:
    print(i)

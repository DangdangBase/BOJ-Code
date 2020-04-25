import sys

a = int(sys.stdin.readline())
nums = []

for i in range(a):
    A,B = map(int, sys.stdin.readline().split())
    nums.append(A+B)

for k in nums:
    print(k)

import sys

n = int(sys.stdin.readline().split()[0])
seq = [0 for i in range(10001)]
cur = 0

for i in range(n):
    cur = int(sys.stdin.readline().split()[0])
    seq[cur] += 1

for i in range(1, 10001):
    for j in range(seq[i]):
        print(i)

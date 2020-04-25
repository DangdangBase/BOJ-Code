import sys

n = int(input())

lsta = list(map(int, sys.stdin.readline().split()))
lstb = list(map(int, sys.stdin.readline().split()))
op = 0

sort_b = sorted(lstb)
sort_b.reverse()
sort_a = sorted(lsta)

for k in range(n):
    idx = lstb.index(sort_b[k])
    op += lstb[idx] * sort_a[k]
    lstb[idx] = -1

print(op)

N = int(input())
seq = list(map(int, input().split()))
seq.append(0)

start = 0
curMax = 0

for i in range(len(seq)-1):
    if seq[i] >= seq[i+1]:
        curMax = max(curMax, seq[i]-seq[start])
        start = i+1


print(curMax)
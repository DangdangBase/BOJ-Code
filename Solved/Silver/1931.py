num = int(input())
count = 0
req = []

for i in range(num):
    a = list(map(int, input().split()))
    req.append(a)

req.sort(key = lambda x : (x[0]))
req.sort(key = lambda x : (x[1]))


last = -1
for k in req:
    if (last <= k[0]) :
        count += 1
        last = k[1]

print(count)

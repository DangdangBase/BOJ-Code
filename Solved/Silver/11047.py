N,K = map(int, input().split())

val = []
count = 0

for i in range(N):
    val.append(int(input()))

val.reverse()


for j in val:
    count += K//j
    K %= j

print(count)

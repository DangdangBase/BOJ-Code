num = int(input())
weight = list(map(int, input().split()))
count = 0

weight.sort()

for i in range(len(weight)):
    if weight[i] > count+1:
        break
    count += weight[i]

print(count + 1)
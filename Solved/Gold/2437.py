num = int(input())
weight = list(map(int, input().split()))
count = 0

weight.sort()

for i in range(num):
    count += weight[i] + 1
    if(count not in weight):
        break
    else:
        count -= 1

print(count)

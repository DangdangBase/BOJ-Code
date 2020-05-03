n = int(input())
seq = list(map(int, input().split()))

LIS = [1]

for i in range(1, n):
    curlis = 0

    for j in range(i):
        if seq[j] < seq[i] and LIS[j] > curlis:
            curlis = LIS[j]

    LIS.append(curlis + 1)

print(max(LIS))
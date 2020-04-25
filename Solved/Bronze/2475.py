num = list(map(int, input().split()))
sum = 0

for i in num:
    sum += i*i

print(sum%10)


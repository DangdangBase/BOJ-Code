a = 1000 - int(input())

count = 0


coins = [500,100,50,10,5,1]


for k in coins:
    count += a//k
    a = a%k

print(count)

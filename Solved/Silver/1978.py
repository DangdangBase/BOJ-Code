import sys

n = int(sys.stdin.readline())
count = 0
ip = list(map(int,sys.stdin.readline().split()))
primenums = [2]

for i in range(2,1000):
    ifprime = True
    for k in range(len(primenums)):
        if(i%primenums[k] == 0):
            ifprime = False
            break
    

    if(ifprime):
        primenums.append(i)


for j in ip:
    if(j in primenums):
        count += 1

print(count)

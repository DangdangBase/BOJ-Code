# times up


n = int(input())

start = 0
end = 0
cur_sum = 2
count = 0
primenums = [2]


for i in range(2,n+1):
    ifprime = True
    for k in range(len(primenums)):
        if(i%primenums[k] == 0):
            ifprime = False
            break
    

    if(ifprime):
        primenums.append(i)


nums = len(primenums)



while(start < nums):
    if(cur_sum == n):
        count += 1
        cur_sum -= primenums[start]
        start += 1

    elif(cur_sum > n or end == nums-1):
        cur_sum -= primenums[start]
        start += 1

    else:
        end += 1
        cur_sum += primenums[end]


print(count)

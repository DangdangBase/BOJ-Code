import sys

n,s = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))


start = 0
end = 0
cur_sum = nums[0]
count = 0



while(start < n):
    if(cur_sum == s):
        count += 1
        cur_sum -= nums[start]
        start += 1
        
    elif(cur_sum > s or end == n-1):
        cur_sum -= nums[start]
        start += 1

    else:
        end += 1
        cur_sum += nums[end]
        



print(count)

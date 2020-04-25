import sys

n,s = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))


start = 0
end = 0
cur_sum = nums[0]
minimum = n

if(sum(nums) < s):
    start = n
    minimum = 0


while(start < n):
    if(cur_sum >= s or end == n-1):
        if(end - start + 1 < minimum):
            minimum = end - start + 1
            
        cur_sum -= nums[start]
        start += 1
    else:
        end += 1
        cur_sum += nums[end]

    print(cur_sum)



print(minimum)

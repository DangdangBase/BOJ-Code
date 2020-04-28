import sys

n = int(input())


nums = []
idx = []

avg = 0
med = 0
mode = 0
rng = 0

for i in range(8001):
    idx.append(0)


for _ in range(n):
    ip = int(sys.stdin.readline().split()[0])

    nums.append(ip)
    idx[ip + 4000] += 1

nums = sorted(nums)
numMax = max(idx)

avg = sum(nums) / n
med = nums[int((n - 1) / 2)]
rng = nums[len(nums)-1] - nums[0]


mode = idx.index(numMax) - 4000
idx.remove(numMax)
if numMax in idx:
    mode = idx.index(numMax) - 3999



print(round(avg))
print(med)
print(mode)
print(rng)
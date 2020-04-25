a = input()

nums = [[i,0] for i in range(10)]
nors = [6,9]
nine_or_six = 0

for i in range(len(a)):
    nums[int(a[i])][1] += 1
    if(int(a[i]) == 9 or int(a[i]) == 6):
        nine_or_six += 1

nums.sort(key = lambda x : -x[1])



div = nine_or_six//2
rem = nine_or_six%2

if(nums[0][0] not in nors):
    print(nums[0][1])
else:
   
    if(rem == 0):
        k = div
    else:
        k = div + 1
        
    if((nums[0][0] in nors) and (nums[1][0] not in nors)):
        if(k > nums[1][1]):
            print(k)
        else:
            print(nums[1][1])
    else:
        print(k)


    
    

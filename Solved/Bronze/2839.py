kg = int(input())

rem = kg%5
num = kg//5

if(rem == 0):
    num = num
elif(rem == 3 or rem == 1):
    num += 1
else:
    if(kg == 7 or kg == 4):
        num = -1
    else:
        num += 2

print(num)



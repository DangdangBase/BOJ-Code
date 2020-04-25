x = int(input())
count = 0

while(x!=1):
    if(x%3 == 0):
        x = x//3
    elif(x%2 == 0):
        x = x//2
    else:
        x -= 1
        
    count += 1


print(count)

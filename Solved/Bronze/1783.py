r,c = map(int, input().split())



if(r == 1):
    tot = 1
    
elif(r == 2):
    if(c == 1 or c == 2):
        tot = 1
    elif(c == 3 or c == 4):
        tot = 2
    elif(c == 5 or c == 6):
        tot = 3
    else:
        tot = 4
        
else:
    if(c <= 4):
        tot = c
    elif(5 <= c and c <= 6):
        tot = 4
    else:
        tot = c-2
        


print(tot)

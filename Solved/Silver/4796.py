ops = []

while(True):
    a = list(map(int, input().split()))
    if(a[0] == a[1] == a[2] == 0):
        break
    else:
        tmp = 0
        tmp = (a[2]//a[1])*a[0]
        
        num = a[2]%a[1]

        if(num >= a[0]):
            tmp += a[0]
        else:
            tmp += num

        ops.append(tmp)

for i in range(len(ops)):
    print("Case " + str(i+1) + ": " + str(ops[i]))

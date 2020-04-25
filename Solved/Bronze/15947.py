num = int(input())

div = num//14
rem = num%14

lsta = [3,4,7,8,11,12]
lstb = ["baby", "sukhwan", 0,0,"very","cute",0,0,"in","bed",0,0,"baby","sukhwan"]

if(rem in lsta):
    if(rem%4 == 3):
        if(div >= 3):
            print('tu+ru*' + str(div+2))
        else:
            print('tu' + 'ru'*(div+2))
    else:
        if(div >= 4):
            print('tu+ru*' + str(div+1))
        else:
            print('tu' + 'ru'*(div+1))

else:
    print(lstb[rem-1])

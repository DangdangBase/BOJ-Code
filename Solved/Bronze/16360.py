lsta = ['ne','a','i','y','l','n','o','r','t','u','v','w']
lstb = ['anes','as','ios','ios','les','anes','os','res','tas','us','ves','was']

num = int(input())

ops = []

for i in range(num):
    a = input()
    if(a[-1] in lsta):
        idx = lsta.index(a[-1])
        ops.append(a[:-1] + lstb[idx])
    elif(a[-2:len(a)] == 'ne'):
        idx = 0
        ops.append(a[:-2] + lstb[idx])
    else:
        ops.append(a+'us')


for k in ops:
    print(k)

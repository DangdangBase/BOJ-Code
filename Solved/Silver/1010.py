import sys

comb_ind = []
str_ind = []

def bridge(n,m):
    if(n == m or n == 1):
        if(n == m):
            return 1
        elif(n == 1):
            return m
    else:
        str1 = str(n) + str(m)
        str2 = str(n) + str(n-m)
        
        if(str1 in str_ind or str2 in str_ind):
            if(str1 in str_ind):
                return comb_ind[str_ind.index(str1)]
            else:
                return comb_ind[str_ind.index(str2)]
        else:
            op = 0
            for i in range(n-1, m):
                op += bridge(n-1, i)
                
            str_ind.append(str1)
            comb_ind.append(op)
            return op



a = int(input())

for k in range(a):
    n,m = map(int, sys.stdin.readline().split())
    print(bridge(n,m))

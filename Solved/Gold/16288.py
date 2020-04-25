can = "YES"

N,K = map(int, input().split())
seq = list(map(int, input().split()))

imgqueue = [[] for k in range(K)]

for i in seq:
    success = False
    
    for j in imgqueue:
        if (not j or j[-1] < i):
            j.append(i)
            success = True
            break

    if(not success):
        can = "NO"
        break

print(can)

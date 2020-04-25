import sys


n = int(sys.stdin.readline())

fibs = [0 for i in range(n+1)]
fibs[0],fibs[1] = 0,1



for k in range(2,n+1):
    fibs[k] = fibs[k-1] + fibs[k-2]



    

print(fibs[n])

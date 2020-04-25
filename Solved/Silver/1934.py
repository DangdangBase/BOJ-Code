import sys


def gcd(a,b):
    r = a%b
    if(r == 0):
        return b
    else:
        return gcd(b,r)



t = int(input())


for i in range(t):
    a,b = map(int, sys.stdin.readline().split())
    k = gcd(a,b)
    n = a*b/k
    print(int(n))

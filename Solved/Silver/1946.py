import sys

t = int(sys.stdin.readline())

for i in range(t):
    n = int(sys.stdin.readline())
    spec = []

    for j in range(n):
        a, b = list(map(int, sys.stdin.readline().split()))
        spec.append([a, b])
        
    spec.sort(key = lambda x: (x[0], x[1]))
    ans = 1
    b_min = spec[0][1]

    for a, b in spec[1:]:
        if b_min > b:
            ans += 1
            b_min = b
        
        if b_min == 1:
            break;

    print(ans)

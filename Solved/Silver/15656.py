from itertools import product


N, M = map(int, input().split())

domain = list(map(int, input().split()))
domain = sorted(domain)

seq = list(product(domain, repeat=M))


for item in seq:
    print(' '.join(map(str, list(item))))
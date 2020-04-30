from itertools import combinations


N, M = map(int, input().split())

domain = list(map(int, input().split()))
domain = sorted(domain)

seq = list(combinations(domain, M))


for item in seq:
    print(' '.join(map(str, list(item))))
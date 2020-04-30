from itertools import combinations_with_replacement


N, M = map(int, input().split())

domain = list(map(int, input().split()))
domain = sorted(domain)

seq = list(combinations_with_replacement(domain, M))


for item in seq:
    print(' '.join(map(str, list(item))))
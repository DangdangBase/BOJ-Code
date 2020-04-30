from itertools import permutations


N, M = map(int, input().split())

domain = list(map(int, input().split()))
domain = sorted(domain)

seq = list(permutations(domain, M))


for item in seq:
    print(' '.join(map(str, list(item))))
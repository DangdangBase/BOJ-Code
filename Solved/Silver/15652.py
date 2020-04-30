from itertools import combinations_with_replacement

N, M = map(int, input().split())

domain = [num for num in range(1, N+1)]
seq = list(combinations_with_replacement(domain, M))

for item in seq:
    print(' '.join(map(str, list(item))))
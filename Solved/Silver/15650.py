import sys
from itertools import combinations

N, M = map(int, input().split())

domain = [num for num in range(1, N+1)]
seq = list(combinations(domain, M))

for item in seq:
    print(' '.join(map(str, list(item))))
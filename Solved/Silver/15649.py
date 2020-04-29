import sys
from itertools import permutations

N, M = map(int, input().split())

domain = [num for num in range(1, N+1)]
seq = list(permutations(domain, M))

for item in seq:
    print(' '.join(map(str, list(item))))
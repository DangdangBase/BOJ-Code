import sys
from itertools import product

N, M = map(int, input().split())

domain = [num for num in range(1, N+1)]
seq = list(product(domain, repeat=M))

for item in seq:
    print(' '.join(map(str, list(item))))
from itertools import combinations

while True:
    ip = list(map(str, input().split()))
    num = ip[0]

    if num == '0':
        break

    op = list(combinations(ip[1:], 6))

    for item in op:
        print(' '.join(item))

    print()

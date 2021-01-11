import sys

cur = input().strip()

if(cur == ''):
    print(0)
    sys.exit()


cnt = 1
for c in cur:
    if c == ' ':
        cnt += 1

print(cnt)
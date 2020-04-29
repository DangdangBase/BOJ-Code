N, L = map(int, input().split())
pipe = list(map(int, input().split()))
pipe = sorted(pipe)

covered = 0;
tapeNum = 0;

for leak in pipe:
    if leak <= covered:
        continue

    tapeNum += 1
    covered = leak + L - 1

print(tapeNum)



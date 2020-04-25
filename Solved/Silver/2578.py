import sys

def count_bingo(rows):
    bingos = 0
    dig1 = 0
    dig2 = 0

    for i in range(5):
        if(sum(rows[i]) == 0):
            bingos += 1

        k = rows[0][i] + rows[1][i] + rows[2][i] + rows[3][i] + rows[4][i]

        if(k == 0):
            bingos += 1
    
        dig1 += rows[i][i]
        dig2 += rows[4-i][i]

    if(dig1 == 0):
        bingos += 1
    if(dig2 == 0):
        bingos += 1

    return bingos

rows = []
for m in range(5):
    rows.append(list(map(int, sys.stdin.readline().split())))

num_seq = []

for i in range(5):
    a = list(map(int, sys.stdin.readline().split()))
    for k in a:
        num_seq.append(k)

count = 0


for j in num_seq:    
    for n in range(5):
        if (j in rows[n]):
            rows[n][rows[n].index(j)] = 0
            count += 1
            break

    g = count_bingo(rows)

    if (g>=3):
        break

print(count)
    

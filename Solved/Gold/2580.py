row = [set() for i in range(9)]
col = [set() for j in range(9)]
box = [set() for k in range(9)]
board = [[] for rownum in range(9)]
unassigned = []


for i in range(9):
    board[i] = list(map(str, input().split()))
    for j in range(9):
        num = int(board[i][j])
        if num == 0:
            unassigned.append((i, j))

        k = i // 3 * 3 + j // 3

        row[i].add(num)
        col[j].add(num)
        box[k].add(num)


def backtrack(startPos):
    if startPos >= len(unassigned):
        return True

    i, j = unassigned[startPos]
    k = i // 3 * 3 + j // 3

    domain = set([num for num in range(1,10)])
    domain -= row[i] | col[j] | box[k]

    for num in list(domain):
        board[i][j] = str(num)
        row[i].add(num)
        col[j].add(num)
        box[k].add(num)

        if backtrack(startPos + 1):
            return True

        board[i][j] = '0'
        row[i].remove(num)
        col[j].remove(num)
        box[k].remove(num)

    return False

backtrack(0)

for i in range(9):
    print(' '.join(board[i]))
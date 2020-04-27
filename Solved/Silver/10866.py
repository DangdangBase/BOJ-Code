import sys

inst = int(input())
queue = []

for _ in range(inst):
    com = list(sys.stdin.readline().split())
    curCom = com[0]
    op = ''
    length = len(queue)

    if curCom == 'push_front':
        queue.insert(0, com[1])

    elif curCom == 'push_back':
        queue.append(com[1])

    elif curCom == 'pop_front':
        if length == 0:
            op = -1
        else:
            op = queue.pop(0)

    elif curCom == 'pop_back':
        if length == 0:
            op = -1
        else:
            op = queue.pop()

    elif curCom == 'size':
        op = length

    elif curCom == 'empty':
        if length == 0:
            op = 1
        else:
            op = 0

    elif curCom == 'front':
        if length == 0:
            op = -1
        else:
            op = queue[0]

    else:
        if length == 0:
            op = -1
        else:
            op = queue[length - 1]

    if op != '':
        print(op)
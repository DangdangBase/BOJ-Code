expr = input()

numBuff = ''
exprList = []
isLastNum = False


for i in range(len(expr)):
    if (expr[i] == '+') or (expr[i] == '-'):
        exprList.append(int(numBuff))
        exprList.append(expr[i])
        isLastNum = False

    else:
        if (not isLastNum):
            numBuff = expr[i]
        else:
            numBuff += expr[i]

        if(i == len(expr)-1):
            exprList.append(int(numBuff))

        isLastNum = True




totSum = 0
partialSum = 0
inParen = False



for i in range(len(exprList)):
    if exprList[i] == '-':
        totSum -= partialSum
        partialSum = 0
        inParen = True

    elif exprList[i] == '+':
        continue

    else:
        if inParen:
            partialSum += exprList[i]
        else:
            totSum += exprList[i]

    if i == len(exprList)-1:
        totSum -= partialSum



print(totSum)
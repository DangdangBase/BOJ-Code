tcs = int(input())

for i in range(tcs):
    testStr = input()
    score = 0
    scorebuffer = 0

    for j in range(len(testStr)):
        if testStr[j] == 'O':
            scorebuffer += 1
            score += scorebuffer
        else:
            scorebuffer = 0

    print(score)
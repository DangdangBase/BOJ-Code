hexnum = input()
length = len(hexnum)
decnum = 0

for i in range(length):
    if(hexnum[i].isalpha()):
        tmp = ord(hexnum[i]) - 87
        decnum += pow(16, length -1 - i) * tmp

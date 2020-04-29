case = input()

barNum = 0
segments = 0
lastExp = ''

for exp in case:
    if exp == "(":
        barNum += 1
    else:
        if lastExp == "(":
            barNum -= 1
            segments += barNum
        else:
            barNum -= 1
            segments += 1
    lastExp = exp

print(segments)
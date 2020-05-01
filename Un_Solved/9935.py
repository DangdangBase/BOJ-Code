target = input()
bomb = input()

idx = target.find(bomb)
bLen = len(bomb)

while (idx != -1 and len(target) != 0):
    target = target[:idx] + target[idx+bLen:]
    idx = target.find(bomb)

if len(target) == 0:
    print("FRULA")
else:
    print(target)
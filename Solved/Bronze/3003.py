a = list(map(int, input().split()))
op = ""

for i in range(6):
    if (i == 0 or i == 1):
        op += str(1 - a[i]) + " "
    elif (i == 5):
        op += str(8 - a[i]) + " "
    else:
        op += str(2 - a[i]) + " "

print(op)

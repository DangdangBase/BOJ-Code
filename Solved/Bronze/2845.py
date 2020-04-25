n,s = map(int, input().split())

a = list(map(int, input().split()))
op = ""

for i in range(5):
    op += str(a[i]-n*s) + " "

print(op)

a = list(map(str,input().split()))
op = []

def carry(a, b):
    if (int(a) + int(b) >= 10):
        

if(len(a[0]) >= len(a[1])):
    length = len(a[0])
    k = "0"*(length-a[1])
    a[1] = k+a[1]
else:
    length = len(a[1])
    k = "0"*(length-a[0])
    a[0] = k+a[0]

for i in range(length):
    

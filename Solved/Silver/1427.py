a = int(input())
b = []
c = ""
d = len(str(a))

for i in range(d):
    b.append(a//pow(10,d-i-1))
    a = a%pow(10,d-i-1)
    
b.sort()
b.reverse()

for k in b:
    c += str(k)

print(c)

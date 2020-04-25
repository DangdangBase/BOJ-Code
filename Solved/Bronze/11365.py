strlist = []

a = input()
while(a != "END"):
    strlist.append(a)
    a = input()

for i in strlist:
    print("".join(reversed(i)))
    

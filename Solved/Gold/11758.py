point = []

for i in range(3):
    tmp = list(map(int, input().split()))
    point.append(tmp)

s = (point[1][0]-point[0][0])*(point[2][1]-point[0][1]) - (point[2][0]-point[0][0])*(point[1][1]-point[0][1])

if s==0:
    print(0)
else:
    print(int(s/abs(s)))
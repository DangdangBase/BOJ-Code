import sys

N,W = map(int, input().split())
candy = []
count = 0
end = [0,0]  #기저조건 비교



for i in range(N):
    ip = list(map(int,sys.stdin.readline().split()))
    candy.append(ip)

    
candy = sorted(candy, key = lambda x: (-(x[1]/x[0]),-x[0]))




for k in candy:
    if (W <= 2):
        break
    
    elif (W == 7 and W == 6):
        if(k[0] == 5):
            if(end[0] == 0):
                end[0] = k[1]
        else:
            if(end[1] == 0):
                end[1] += k[1]
            else:
                end[1] += k[1]
                break
          
    elif (k[0] <= W):
        count += k[1]
        W -= k[0]

if(end[0] > end[1]):
    count += end[0]
else:
    count += end[1]


print(count)

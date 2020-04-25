import sys

n,m = map(int, input().split())

chic_count = 0
chic_loc = []
city = []

for y in range(n):
    row = list(map(int, sys.stdin.readline().split()))
    city.append(row)

    
# set chicken seller's location
for r in range(n):
    for c in range(n):
        if(city[r][c] == 2):
            chic_count += 1
            a = []
            a.append(r)
            a.append(c)
            chic_loc.append(a)



# set chicken distance for every chic_seller/house
chic_dist = [[] for i in range(chic_count)]
house_num = 0

for r in range(n):
    for c in range(n):
        if(city[r][c] == 1):
            house_num += 1
            for i in range(chic_count):
                dist = abs(chic_loc[i][0]-r) + abs(chic_loc[i][1]-c)
                chic_dist[i].append(dist)


for k in chic_dist:
    a = sum(k)
    k.append(a)

chic_dist.sort(key = lambda x : x[house_num])

house_dist = [[] for i in range(house_num)]

for i in range(m):
    for k in range(house_num):
        house_dist[k].append(chic_dist[i][k])



lowest = 0

for i in range(house_num):
    lowest += min(house_dist[i])

print(lowest)


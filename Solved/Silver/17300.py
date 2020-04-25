l = int(input())
pattern = list(map(int, input().split()))
can = "YES"


dot_idx = [2,2,4,4,5,5,5,5,5,5,5,5,6,6,8,8]
dot_adv = ['13','31', '17','71', '19','91','37','73','28','82','46','64', '39','93', '79','97']

# check if dot had duplicated
for i in range(1,10):
    if(pattern.count(i) >= 2):
        can = "NO"


pat_str = ""

for i in range(l):
    pat_str += str(pattern[i])



for k in range(l-1):
    if(pat_str[k:k+2] in dot_adv):
        idx = dot_adv.index(pat_str[k:k+2])
        if((str(dot_idx[idx]) not in pat_str) or pat_str.index(str(dot_idx[idx])) > k):
            can = "NO"


print(can)

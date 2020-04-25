ip = input()
freq = [[65+i,0]for i in range(26)]

for k in range(len(ip)):
    if(int(ord(ip[k])) >= 97):
        a = int(ord(ip[k])) -97
    else:
        a = int(ord(ip[k]))-65

    freq[a][1] += 1

freq.sort(key = lambda x : x[1])
freq.reverse()

if(freq[0][1] == freq[1][1]):
    print("?")
else:
    print(chr(freq[0][0]))

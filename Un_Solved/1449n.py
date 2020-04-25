N,L = map(int, input().split())
leak = list(map(int,input().split()))

count = 0
last = 0
idx = 0

def move():
    while(True):
        global idx, last
        if(leak[idx] >  last):
            break
        else:
            idx += 1



while(True):
    move()
    
    last += leak[idx] + L
    count += 1
    if(last >= leak[-1]):
        break

print(count)
    

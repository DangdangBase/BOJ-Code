tsg = int(input())
liq = list(map(int,input().split()))

op = [0,0]
op_sum = float("inf")

for i in range(tsg-1):
    if(abs(liq[i] + liq[i+1]) < op_sum):
        op_sum = liq[i] + liq[i+1]
        op[0],op[1] = liq[i],liq[i+1]

print(op)

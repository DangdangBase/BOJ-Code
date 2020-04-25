import sys



n = int(input())
n_str = 0
c_str = 0
nc_str = 0
none_str = 0


div = 1000000007


for i in range(n):
    a = sys.stdin.readline()

    if('NC' in a):
        nc_str += 1
    elif("N" in a):
        n_str += 1
    elif("C" in a):
        c_str += 1
    else:
        none_str += 1




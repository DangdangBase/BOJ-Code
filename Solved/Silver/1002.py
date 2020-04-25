import sys
import math

tc = int(sys.stdin.readline())
loc = []


for i in range(tc):
    imf = list(map(int, sys.stdin.readline().split()))

    dot_dist = math.sqrt((imf[0]-imf[3])**2 + (imf[1]-imf[4])**2)
    rad_dif = abs(imf[2] - imf[5])
    rad_sum = imf[2] + imf[5]
            
    
    if(dot_dist == 0):
        if(rad_dif == 0):
            print('-1')
        else:
            print('0')

    else:
        if(dot_dist == rad_dif or dot_dist == rad_sum):
            print('1')
        elif(dot_dist < rad_dif or dot_dist > rad_sum):
            print('0')
        elif(dot_dist > rad_dif and dot_dist < rad_sum):
            print('2')

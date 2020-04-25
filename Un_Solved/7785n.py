import sys

logs = int(input())
on_duty = []

for i in range(logs):
    people,state = map(str, sys.stdin.readline().split())
    if(state == "enter"):
        on_duty.append(people)
    else:
        idx = on_duty.index(people)
        del on_duty[idx]

on_duty.sort()
on_duty.reverse()

for k in on_duty:
    print(k)

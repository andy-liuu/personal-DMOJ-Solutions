#CCC '00 S4 - Golf
import sys
input = sys.stdin.readline

#get inputs
dist = int(input())
num = int(input())
stroke = []

for i in range(num):
    stroke.append(int(input()))

#model dp
field = [0]+[9999]*(dist)

for ind in range(dist):
    now = field[ind]
    for s in stroke:
        if ind+s < dist+1:
            if field[ind+s] > now+1:
                field[ind+s] = now+1
ans = field[-1]
if ans == 0 or ans == 9999:
    print("Roberta acknowledges defeat.")
else:
    print("Roberta wins in %d strokes." %(ans))

#knight hop
#shortest path method

#make the graph
from pprint import *
from queue import *

def findmoves(a,b):
    output = []
    for i in [-1,1]:
        for j in [-2,2]:
            if 0<=a+i<=7 and 0<=b+j<=7:
                output.append((a+i,b+j))
            if 0<=b+i<=7 and 0<=a+j<=7:
                output.append((a+j,b+i))
    return output

graph = {}
for a in range(8):
    for b in range(8):
        graph[(a,b)] = findmoves(a,b)
        
#get inputs
startx,starty = [int(q) for q in input().split()]
endx,endy = [int(t) for t in input().split()]

#shortest path method
distances = [[999999999]*8 for s in range(8)]
distances[startx-1][starty-1] = 0

pts = Queue()
pts.put((startx-1,starty-1))

while not pts.empty():
    cx,cy = pts.get()
    for (px,py) in graph[(cx,cy)]:
        if distances[cx][cy] + 1 < distances[px][py]:
            distances[px][py] = distances[cx][cy] + 1
            pts.put((px,py))
print(distances[endx-1][endy-1])

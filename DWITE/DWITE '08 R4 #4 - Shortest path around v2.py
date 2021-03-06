#shortest path around
import sys
input = sys.stdin.readline
from queue import *
from pprint import *
for _ in range(5):
    #make graph
    graph = [[0]*8 for i in range(8)]
    ends = []

    for x in range(8):
        line = input()
        for y in range(8):
            if line[y] == "." or line[y] == "A" or line[y] == "B":
                row = []
                for q in (-1,0,1):
                    xx = x+q
                    for w in (-1,0,1):
                        yy = y+w
                        if 0<=xx<8 and 0<=yy<8:
                            row.append((xx,yy))
                graph[x][y] = row
                
                if line[y] == "A" or line[y] == "B":
                    ends.append((x,y))
            elif line[y] == "#":
                graph[x][y] = []
    
    #model shortest path method

    (startx,starty) = ends[0]
    (endx,endy) = ends[1]
    dist = [[9999]*8 for i in range(10)]
    dist[startx][starty] = 0
    nextup = Queue()
    nextup.put((startx,starty))

    while not nextup.empty():
        cur = nextup.get()
        
        cx,cy = cur

        for nx,ny in graph[cx][cy]:
            if dist[cx][cy] + 1 < dist[nx][ny]:
                dist[nx][ny] = dist[cx][cy] + 1
                nextup.put((nx,ny))
    
    print(dist[endx][endy])

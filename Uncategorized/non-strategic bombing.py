#non-strategic bombing
#check if point in polygon
from math import *

def findarea(x1,y1,x2,y2,x3,y3):
    area = 0.5*abs((x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3))
    return area
n,m = [int(_) for _ in input().split()]

city = []
for i in range(n):
    x,y = [int(r) for r in input().split()]
    city.append((x,y))

triangles = []
for q in range(m):
    a,b,c,d,e,f = [int(z) for z in input().split()]
    triangles.append(((a,b),(c,d),(e,f)))

#use areas to find wether the point isinside or outside

for tri in triangles:
    count = 0
    (q,w),(e,r),(t,y) = tri
    vol = findarea(q,w,e,r,t,y)
    maxx,minx = max(q,e,t),min(q,e,t)
    maxy,miny = max(w,r,y),min(w,r,y)
    for pt in city:
        h,j = pt
        if minx<=h<=maxx and miny <= j <= maxy:
            if findarea(q,w,e,r,h,j) + findarea(q,w,h,j,t,y) + findarea(h,j,e,r,t,y) == vol:
                count += 1
    print(count)
                            




    
        
    

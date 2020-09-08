import sys
input = sys.stdin.readline




t = int(input())

for _ in range(t):


    n = int(input())
    ans = ""

    
    for q in range(n):


        top = 9999
        bot = -1
        left = 9999
        right = -1

        

        
        grid = []
        h,w = [int(x) for x in input().strip().split()]

        #get inputs, find borders
        for k in range(h):
            line = input()
            grid.append(line)

            
            #has *
            if not line.find("*") == -1:
                
                top = min(top, k)
                bot = max(bot, k)

                left = min(left, line.find("*"))
                right = max(right, line.rfind("*"))

        #print (top, bot, left, right)
        
        if left == right:
            ans += "1"
            
        elif (bot - top)%2 != 0:
            ans += "7"

        elif grid[top][right] == "*" and grid[top][left] == "*":
            ans += "4"

        else:

            mid = (bot + top) // 2 

            if grid[mid].find("*") == -1:
                ans += "0"

            else:
                UR = grid[top + 1][right]
                UL = grid[top + 1][left]
                BR = grid[bot - 1][right]
                BL = grid[bot - 1][left]

                rest = [UR, UL, BR, BL]

                if rest == ["*", "-", "-", "*"]:
                    ans += "2"
                elif rest == ["*", "-", "*", "-"]:
                    ans += "3"
                elif rest == ["-", "*", "*", "-"]:
                    ans += "5"
                elif rest == ["-", "*", "*", "*"]:
                    ans += "6"
                elif rest == ["*", "*", "*", "*"]:
                    ans += "8"
                elif rest == ["*", "*", "*", "-"]:
                    ans += "9"

                
        
        

    print(ans)

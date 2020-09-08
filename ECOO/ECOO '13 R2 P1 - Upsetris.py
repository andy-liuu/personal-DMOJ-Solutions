

import sys
input = sys.stdin.readline



for _ in range(5):

    #get inputs
    cont = True
    size = -1


    temp = input().strip()
    size = len(temp)
    ocount = [0] * (size - 1)


    numrows = 0
    numrows += 1
    for i in range(1, len(temp)-1 , 1):
        
        if temp[i] == "O":
            ocount[i] += 1
        elif temp[i] == "=":
           cont = False
           break



    while (cont):
        numrows += 1
        temp = input().strip()
        size = len(temp)

        for i in range(1, len(temp) - 1, 1):
            if temp[i] == "O":
                ocount[i] += 1
            elif temp[i] == "=":
                cont = False
                break
        

    ocount = ocount[1:size-1]


    #remove minnimums
    minn = 9999
    for x in ocount:
        if x < minn:
            minn = x

    for i in range(len(ocount)):
        ocount[i] -= minn

    ocount = ocount[::-1]

    #print final board
    for x in range(numrows - 1):
        ans = ""
        ans += "|"


        for s in range(len(ocount)):
            if ocount[s] >= numrows - 1 - x:
                ans += 'O'
            else:
                ans += " "
        ans += "|"
        print(ans)

    print ( "|" + "=" * (size - 2) + "|")
            

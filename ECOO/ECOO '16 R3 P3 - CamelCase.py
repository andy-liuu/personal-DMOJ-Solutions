from sys import *
input = stdin.readline

#dictionary is same as hashtable
words = {}

n = int(input())
for i in range(n):
    temp = input().strip()
    words[temp.lower()] = temp.lower()


#loop here

for qqq in range(10):
    test = input()

    dp = [0 for _ in range(len(test))]
    


    for x in range(1, len(test) + 1):
        for y in range(x):
            if test[y:x].lower() in words:


                if dp[x] == 0:
                    dp[x] = dp[y]+1
                else:
                    dp[x] = min(dp[x], dp[y] + 1)

    print(max(dp[-1]-1,0))

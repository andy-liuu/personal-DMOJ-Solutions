

def checkBabyTalk(word):

    if len(word)%2 == 1:
        return False
    else:
        if word[:len(word)//2] == word[len(word)//2 :]:
            return True
        return False


for q in range(10):

    line = input()
    size = len(line)


    ans = 0

    dp = [0 for _ in range(size+2)]

    for i in range(1,size+1):
        for j in range(i):
            if checkBabyTalk(line[j:i]):
                dp[i] = max( dp[j] + len(line[j:i]), dp[i])

                if dp[i] > ans:
                    ans = dp[i]
                

    #print(dp)
    print(ans)
        

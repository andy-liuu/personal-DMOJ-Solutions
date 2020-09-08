
import sys
input = sys.stdin.readline



'''length of word'''
def length(word):
    #print (len(word)*4)
    return len(word)*4

''' _basics requirement'''
def basics(word):
    

    siz = 0

    
    hasUp = False
    hasLow = False
    hasNum = False
    hasSym = False
    
    for char in word:
        siz += 1

        #is Upper
        if 'A'<=char<='Z':
            hasUp = True

        elif 'a'<=char<'z':
            hasLow = True

        elif '0'<=char<='9':
            hasNum = True
        else:
            hasSym = True

    numConds = hasUp + hasLow + hasNum + hasSym

    if siz >= 8 and numConds >= 3:
        #print(2 + numConds*2)
        return 2 + numConds*2
    #print(0)
    return 0;

def cases(word):
    siz = 0

    
    numUp = 0
    numLow = 0
    numNum = 0
    numSym = 0
    
    for char in word:
        siz += 1

        if 'A'<=char<='Z':
            numUp += 1

        elif 'a'<=char<'z':
            numLow += 1

        elif '0'<=char<='9':
            numNum +=1
        else:
            numSym += 1

    ans = 0

    #uppers
    if numUp != 0:
        #print((siz-numUp)*2)
        ans += (siz-numUp)*2

    #lowers
    if numLow != 0:
        #print((siz-numLow)*2)
        ans += (siz-numLow)*2


    #numbers AND numbers only
    if numNum < siz:
        #print(4*numNum)
        ans += 4*numNum
    else:
        #print (-1*siz)
        ans -= siz


    #symbols
    #print(6*numSym)
    ans += 6*numSym

    #letters only
    if numUp + numLow == siz:
        #print (-1*siz)
        ans -= siz


    
    return ans


def midDigs(word):
    numUp = 0
    numLow = 0
    numNum = 0
    numSym = 0

    for i in range(1,len(word)-1):
        char = word[i]
        if 'A'<=char<='Z':
            numUp += 1

        elif 'a'<=char<'z':
            numLow += 1

        elif '0'<=char<='9':
            numNum +=1
        else:
            numSym += 1

    #print(2*(numNum + numSym))
    #print (2*(numNum + numSym))
    return 2*(numNum + numSym)


def getType(let):
    if 'A'<=let<='Z':
        return "UP"

    elif 'a'<=let<='z':
        return "LOW"

    elif '0'<=let<='9':
        return "DIG"
    else:
        return "SYM"

def consecCases(word):
    ans = 0
    cur = 0

    #print(prevType)

    for i in range(len(word)-1):
        
        cur += 1

        #reset case
        if getType(word[i]) != getType(word[i+1]):
            if getType(word[i]) != "SYM":
                #print(2*(cur-1))
                ans -= 2*(cur-1)
            cur = 0

    #last case
    if getType(word[-1]) == getType(word[len(word)-2]):
        cur += 1
        if getType(word[-1]) != "SYM":
            #print(2*(cur-1))
            ans -= 2*(cur-1)
        cur = 0

    #print(ans) 
    return ans
    

def sequentialNums(word):

    
    ans = 0
    
    prev = -1
    size = 0
    maxi = 0

    #forward sequence of numbers
    for i in range(len(word)):
        if i == 0:
            prev = ord(word[i])
            size += 1
        else:

            cur = ord(word[i])

            if cur == prev + 1 and '0'<=word[i]<='9':
                prev = cur
                size += 1

            else:
                maxi = max(maxi,size)
                size = 1
                prev = cur
        
    maxi = max(maxi,size)


    #backwards loop
    prev = -1
    size = 0
    maxid = 0

    
    for i in range(len(word)):
        if i == 0:
            prev = ord(word[i])
            size += 1
        else:

            cur = ord(word[i])

            if cur == prev - 1 and '0'<=word[i]<='9':
                prev = cur
                size += 1

            else:
                maxi = max(maxi,size)
                size = 1
                prev = cur
        
    maxid = max(maxi,size)

    
    
    maxxx = max(maxi,maxid)

    if maxxx >= 3:
        ans -= 3*(maxxx-2)

        
    #print(ans)                         
    return ans


def sequentialLow(word):

    
    ans = 0
    
    prev = -1
    size = 0
    maxi = 0

    #forward sequence of numbers
    for i in range(len(word)):
        if i == 0:
            prev = ord(word[i])
            size += 1
        else:

            cur = ord(word[i])

            if cur == prev + 1 and 'a'<=word[i]<='z':
                prev = cur
                size += 1

            else:
                maxi = max(maxi,size)
                size = 1
                prev = cur
        
    maxi = max(maxi,size)


    #backwards loop
    prev = -1
    size = 0
    maxid = 0

    
    for i in range(len(word)):
        if i == 0:
            prev = ord(word[i])
            size += 1
        else:

            cur = ord(word[i])

            if cur == prev - 1 and 'a'<=word[i]<='z':
                prev = cur
                size += 1

            else:
                maxi = max(maxi,size)
                size = 1
                prev = cur
        
    maxid = max(maxi,size)

    
    
    maxxx = max(maxi,maxid)

    if maxxx >= 3:
        ans -= 3*(maxxx-2)

        
    #print(ans)                         
    return ans       

def sequentialUp(word):

    
    ans = 0
    
    prev = -1
    size = 0
    maxi = 0

    #forward sequence of numbers
    for i in range(len(word)):
        if i == 0:
            prev = ord(word[i])
            size += 1
        else:

            cur = ord(word[i])

            if cur == prev + 1 and 'A'<=word[i]<='Z':
                prev = cur
                size += 1

            else:
                maxi = max(maxi,size)
                size = 1
                prev = cur
        
    maxi = max(maxi,size)


    #backwards loop
    prev = -1
    size = 0
    maxid = 0

    
    for i in range(len(word)):
        if i == 0:
            prev = ord(word[i])
            size += 1
        else:

            cur = ord(word[i])

            if cur == prev - 1 and 'A'<=word[i]<='Z':
                prev = cur
                size += 1

            else:
                maxi = max(maxi,size)
                size = 1
                prev = cur
        
    maxid = max(maxi,size)

    
    
    maxxx = max(maxi,maxid)

    if maxxx >= 3:
        ans -= 3*(maxxx-2)

        
    #print(ans)                         
    return ans



#loop x10 here

for qwe in range(10):

    word = input().strip()


    wans = 0
    wans += length(word)
    wans += basics(word)
    wans += cases(word)
    wans += midDigs(word)
    wans += consecCases(word)
    wans += sequentialNums(word)

    '''
    print (length(word))
    print (basics(word))
    print (cases(word))
    print (midDigs(word))
    print (consecCases(word))
    print (sequentialNums(word))
    '''

    #print (min(sequentialLow(word),sequentialUp(word)))
    wans += min(sequentialLow(word),sequentialUp(word))





    if wans <= 20:
        print("Very Weak (score = %d)" %max(wans,0))
    elif 21 <= wans <= 40:
        print("Weak (score = %d)" %wans)
    elif 41 <= wans <= 60:
        print("Good (score = %d)" %wans)
    elif 61 <= wans <= 80:
        print("Strong (score = %d)" %wans)
    else:
        print("Very Strong (score = %d)" %min(wans,100))















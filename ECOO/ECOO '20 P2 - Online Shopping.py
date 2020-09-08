t = int(input())

for _ in range(t):
    

    n = int(input())

    items = dict()

    for i in range(n):
        m = int(input())

        for r in range(m):
            s,p,q = input().strip().split()
            p = int(p)
            q = int(q)

            #already in
            if s in items.keys():
                items[s].append((p,q))
                items[s].sort()
            else:
                items[s] = [(p,q)]

    k = int(input())

    
    ans = 0

    
    
    for g in range(k):
        
        name, quan = input().strip().split()
        
        quan = int(quan)

        while quan > 0:
            (pri,amount) = items[name].pop(0)
            

            #take all
            if amount <= quan:
                quan -= amount
                ans += (pri * amount)

            #dont take all
            else:
                
                ans += (pri * quan)
                quan = 0
        

    print(ans)

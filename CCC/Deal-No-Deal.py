#CCC '07 J3 - Deal or No Deal Calculator
dollars = [100,500,1000,5000,10000,25000,50000,100000,500000,1000000]

n  = int(input())
for i in range(n):
    num = int(input())
    dollars[num-1] = "taken"

offer = int(input())

#calculate average
tot = 0
count = 0
for item in dollars:
    if item != "taken":
        tot += item
        count += 1

ave = tot/count

if offer > ave:
    print("deal")
else:
    print("no deal")

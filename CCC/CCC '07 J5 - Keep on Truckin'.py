#CCC '07 J5 - Keep on Truckin'

#get basic inputs
motels = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
mindist = int(input())
maxdist = int(input())
n = int(input())
for i in range(n):
    motels.append(int(input()))

motels.sort()


combos = [1] + [0]*(len(motels)-1)

for spot in range(len(motels)):
    mindrive = motels[spot]+mindist
    maxdrive = motels[spot]+maxdist

    for stay in motels[spot:]:
        if mindrive<=stay<=maxdrive:
            ind = motels.index(stay)
            combos[ind] += combos[spot]

print(combos[-1])             

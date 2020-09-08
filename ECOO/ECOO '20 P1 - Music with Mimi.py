notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']



n = int(input())

for i in range(n):
    lets = input().strip().split()

    nums = [0,0,0,0]

    
    nums[0] = notes.index(lets[1]) - notes.index(lets[0])
    nums[0] += 12
    nums[0] = nums[0] % 12


    nums[1] = notes.index(lets[2]) - notes.index(lets[1])
    nums[1] += 12
    nums[1] = nums[1] % 12

    nums[2] = notes.index(lets[3]) - notes.index(lets[2])
    nums[2] += 12
    nums[2] = nums[2] % 12


    nums[3] = notes.index(lets[0]) - notes.index(lets[3])
    nums[3] += 12
    nums[3] = nums[3] % 12

    if nums == [4,3,3,2]:
        print('root')
    elif nums == [3,3,2,4]:
        print ("first")
    elif nums == [3,2,4,3]:
        print("second")
    elif nums == [2,4,3,3]:
        print("third")
    else:
        print("invalid")
    

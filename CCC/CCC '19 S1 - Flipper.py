hor = False
vert = False

line = input()

for i in line:
    
    if i == "H":
        hor = not hor

    if i == "V":
        vert = not vert

if not hor and not vert:
    print("1 2")
    print("3 4")
elif hor and not vert:
    print("3 4")
    print("1 2")
elif not hor and vert:
    print("2 1")
    print("4 3")
    
elif hor and vert:
    print("4 3")
    print("2 1")

while True:
    try:
        height = int(input("Height: "))
        if (height >= 1) and (height <= 8):
            break
    except:
        print("", end="") # Printing nothing and continuing the loop

for i in range(int(height)):
        print((int(height) - i - 1) * " " + (i + 1) * "#")
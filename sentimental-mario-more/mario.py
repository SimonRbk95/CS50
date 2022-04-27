
def valid_input():
    while True:
        height = int(input("Height: "))
        if height <= 8:
            return height

for i in range(valid_input()):
    print(" " * i, end="")
    print("#")





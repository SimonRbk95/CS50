
def valid_input():
    while True:
        height = int(input("Height: "))
        if height <= 8:
            return height

height = valid_input()
for i in range(height):
    print(" " * height-i, end="")
    print("#")





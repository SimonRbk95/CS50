
def main():
    height = valid_input()
    make_pyramide(heigh)


def valid_input():
    while True:
        height = int(input("Height: "))
        if height <= 8:
            return height


def make_pyramide(height):
    for i in range(height):
        print(" " * (height-i), end="")
        print("#" * (i + 1), end="")
        print(" ", end="")
        print("#" * (i + 1), end="")
        print(" " * (height-i))

if __name__ == "__main__:
    main()

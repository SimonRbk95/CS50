
def main():
    height = valid_input()
    make_pyramide(height)


def valid_input():
    while True:
        try:
            height = int(input("Height: "))
        # if user provides a string, prompt again
        except:
            height = int(input("Height: "))
        if height <= 8 and height > 0:
            return height


def make_pyramide(height):
    for i in range(height):
        print(" " * (height-i), end="")
        print("#" * (i + 1), end="")
        print("  ", end="")
        print("#" * (i + 1))

if __name__ == "__main__":
    main()

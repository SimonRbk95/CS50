
def main():
    height = valid_input()
    make_pyramide(height)


def valid_input():
    while True:
        try:
            height = int(input("Height: "))
        # if user provides a string, prompt again
        except ValueError:
            height = int(input("Height: "))
        if height <= 8 and height > 0:
            return height


def make_pyramide(height):
    for i in range(height):
        # print space before first pyramide half
        print(" " * (height - i - 1), end="")
        # prints first row's pyramide half
        print("#" * (i + 1), end="")
        # whitepsace in the middle
        print("  ", end="")
        # prints second row's pyramide half, including a new line
        print("#" * (i + 1))


if __name__ == "__main__":
    main()


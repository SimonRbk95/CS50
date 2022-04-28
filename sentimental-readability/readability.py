import string


def main():
    text = input("Text: ")
    return text



def count_letters(text):
    # count character
    count = 0
    words = text.split()
    for word in words:
        for letter in word:
            if letter.isalpha:
                print(letter)
                count +=1
    return count




def count_words(text):
    word_count = len(text.split())
    return word_count


def count_sentences(text):
    count_one = len(text.split())
    pass


def grade_calculator():
    pass


if __name__ == "__main__":
    text = main()
    print(count_letters(text))

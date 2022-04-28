import string


def main():
    text = input("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    grade = grade_calculator(letters, words, sentences)
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")



def count_letters(text):
    # count character
    count = 0
    words = text.split()
    for word in words:
        for letter in word:
            if letter.isalpha():
                count +=1
    return count


def count_words(text):
    word_count = len(text.split())
    return word_count


def count_sentences(text):
    count = 0
    # count sentences by counting '.', '!', and '?'
    for words in text:
        for word in words:
            for char in word:
                if ord(char) == 33 or ord(char) == 63 or ord(char) == 46:
                    count +=1
    return count


def grade_calculator(letters, words, sentences):
    L = letters / words * 100
    S = sentences / words * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)
    return grade


if __name__ == "__main__":
    main()
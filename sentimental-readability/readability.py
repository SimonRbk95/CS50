import string


def main():
    text = input("Text: ")
    letters = count_letters(text)
    print(letters)
    words = count_words(text)
    print(words)
    sentences = count_sentences(text)
    print(sentences)
    grade = grade_calculator(letters, words, sentences)
    print(grade)


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
                if ord(char) != 33 and ord(char) != 63 and ord(char) != 46:
                    count +=1
    return count


def grade_calculator(letters, words, sentences):
    L = float(letters) / float(words) * 100
    S = float(sentences) / float(words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    print(index)
    grade = round(index)
    return grade


if __name__ == "__main__":
    main()
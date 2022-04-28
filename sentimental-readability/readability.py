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
                if ord(char) != 33 or ord(char) != 63 or ord(char) != 46:
                    count +=1
    return count


def grade_calculator(letters, words, sentences):
    L = float(letters) / float(words) * 100
    S = float(sentences) / float(words) * 100
    



if __name__ == "__main__":
    text = main()
    print(count_letters(text))
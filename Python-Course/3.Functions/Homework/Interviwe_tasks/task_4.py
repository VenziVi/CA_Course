# 4. Write a function. For a given sentence, return the average word length.
# Note: Remember to remove punctuation first.

# sentence1 = "Hi all, my name is Tom...I am originally from Australia."
# sentence2 = "I need to work very hard to learn more about algorithms in Python!"

# Output:
# 4.2
# 4.08
import re


def avg_word_len(sentence):
    lst = []
    for char in sentence:
        if char.isalpha() or char.isspace():
            lst.append(char)

    words = "".join(lst).split(" ")
    sum = 0
    for word in words:
        sum += len(word)

    avg = sum / len(words)
    return "{:.2f}".format(avg)


print(avg_word_len("Hi all, my name is Tom...I am originally from Australia."))
print(avg_word_len("I need to work very hard to learn more about algorithms in Python!"))
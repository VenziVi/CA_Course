# 9. Write a Python function that takes a list of words and return the longest word and the length of the longest one.

# Input: ["Python", "Exercises", "Great"]
# Output:
# Longest word:  Exercises
# Length of the longest word:  9

def find_longest_word(words):
    if not words:
        return None, 0

    longest_word = max(words, key=lambda x: len(x))
    return longest_word, len(longest_word)


test = ["Python", "Exercises", "Great"]
word, length = find_longest_word(test)
print(word)
print(length)

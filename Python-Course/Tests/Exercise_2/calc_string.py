import re


class CalcString:
    def __init__(self):
        self.sentence = input("Enter string: ")

    def calc_freq(self):
        result = {}
        words = re.findall(r"[A-Za-z]+", self.sentence)
        for word in words:
            if not result.get(word):
                result[word] = 0
            result[word] += 1
        return dict(sorted(result.items()))

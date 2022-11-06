# 2.Write a program to create a recursive function to calculate the sum of
# numbers from random number to random number (0-100).
from random import randrange


def recursive_calc(start, end):
    if start == end:
        return start
    return start + recursive_calc(start+1, end)


def calc_sum(min_range, max_range):
    start = randrange(min_range, max_range + 1)
    end = randrange(min_range, max_range + 1)
    print(start, end)

    if end < start:
        return recursive_calc(end, start)
    return recursive_calc(start, end)


print(calc_sum(0, 100))

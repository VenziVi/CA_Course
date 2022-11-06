
# 6. Write a python function which find all prime divisors of a number and return list from them.
from math import sqrt


def check_is_prime_number(number):
    """
    :param number:
    :return bool:
    """
    if number <= 1:
        return False

    for i in range(2, int(sqrt(number)) + 1):
        if number % i == 0:
            return False

    return True # If number is 1, what is  the return value?

def find_prime_divisors(number, prime_list):
    """
    Given one integer , find all prime divisors of a number.
    Definition: A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
    Example:
    Input : 60
    Output: [2, 3, 5]
    :param number:
    :param prime_list:
    :return: prime_list
    """

    for num in range(2, number + 1):
        if number % num == 0 and check_is_prime_number(num):
            prime_list.append(num)

    return prime_list

print("Prime devisors: ", find_prime_divisors(60, []))


# 7. Write a python function which  Reverse word in string.
#     Extra task: find count of words in string.


def reverse_words_from_string(input_string):
    """
       Given a string , reverse words.
       Example:
       Input : Today is our Python exercises with group one from strypes-03 course.
       Output: course. strypes-03 from one group with exercises Python our is Today
       :param string:
       :return: reversed string
    """
    str_list = input_string.split(" ")
    str_list.reverse()
    return " ".join(str_list)


print("Reversed words: ", reverse_words_from_string("Today is our Python exercises with group one from strypes-03 course."))


def reverse_number(number):
    reversed_num = 0
    while number > 0:
        reversed_num = reversed_num * 10 + (number % 10)
        number //= 10

    return reversed_num

def reversed_integer(number):
    """
        Given an integer, return the integer with reversed digits.
        Note: The integer could be either positive or negative.
        Example:
        Input : -258
        Output: -852
        :param number:
        :return: reversed number
    """
    if number < 0:
        return -reverse_number(abs(number))
    return reverse_number(number)

def reversed_integer_with_str(number):
    """
        Given an integer, return the integer with reversed digits.
        Note: The integer could be either positive or negative.
        Example:
        Input : -258
        Output: -852
        :param number:
        :return: reversed number
    """
    if number < 0:
        return (int("-" + str(number)[:0:-1]))
    return (int(str(number)[::-1]))


print("Reversed integer with str: ", reversed_integer_with_str(-654321))
print("Reversed integer: ", reversed_integer(-654321))


def factorial_number(n):
    """
        Write a Python function to calculate the factorial of a number (a non-negative integer).
        The function accepts the number as an argument.
        Example:
        Input : 6
        Output: 720
        :param number:
        :return: n factorial
    """
    fact = 1
    for num in range(1, n + 1):
        fact = fact * num

    return fact


print("Factorial sum: ", factorial_number(0))


def is_perfect_number(number):
    """
        Write a Python function to check whether a number is perfect or not.
        According to Wikipedia : In number theory, a perfect number is a positive integer that is equal to the sum of
        its proper positive divisors, that is, the sum of its positive divisors excluding the number itself
        (also known as its aliquot sum). Equivalently, a perfect number is a number that is half the sum of all
        of its positive divisors (including itself).
        Example : The first perfect number is 6, because 1, 2, and 3 are its proper positive divisors, and 1 + 2 + 3 = 6
        Equivalently, the number 6 is equal to half the sum of all its positive divisors: ( 1 + 2 + 3 + 6 ) / 2 = 6.
        The next perfect number is 28 = 1 + 2 + 4 + 7 + 14. This is followed by the perfect numbers 496 and 8128
        Input : 6
        Output: True
        :param number:
        :return: is perfect or not?
    """
    sum = 0
    for num in range(1, number // 2 + 1):
        if (number % num == 0):
            sum += num

    return sum == number

print("Is perfect number: ", is_perfect_number(28))
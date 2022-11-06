# 6. Write a program to check a number is Armstrong or not in python programming language
# What is Armstrong Number?
# It is a number which is equal to the sum of cube of its digits.
# For eg: 153, 370 etc.
# Let's see it practically by calculating it,
#
# Suppose I am taking 153 for an example
#
# First calculate the cube of its each digits
#
#   1^3 = (1*1*1) = 1
#
#   5^3 = (5*5*5) = 125
#
#   3^3= (3*3*3) = 27
#
# Now add the cube
#
#   1+125+27 = 153
#
# It means 153 is an Armstrong number.
#

def is_armstrong_number(number):
    if not number.isdigit():
        return False

    sum = 0
    for digit in number:
        sum += pow(int(digit), len(number))

    if sum == int(number):
        return True
    return False


print(is_armstrong_number("153"))
print(is_armstrong_number("asd"))
print(is_armstrong_number("11"))
print(is_armstrong_number("371"))
print(is_armstrong_number("1634"))
print(is_armstrong_number("8208"))

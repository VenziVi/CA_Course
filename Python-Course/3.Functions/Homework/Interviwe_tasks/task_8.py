# 8 . Write a Python program to find l.c.m. of two numbers
# For any two numbers given by the user as an input, we have to calculate and print the l.c.m. of that numbers
# using python programming language.
# Case1: If the user inputs the numbers 4 and 6.
#
#              then the output should be ‘12’.
#
# Case2: If the user inputs the numbers 5 and 7.
#
#             then the output should be ‘35’.


def find_l_c_m(num_1, num_2):
    biggest = num_1 if num_1 > num_2 else num_2
    while True:
        if biggest % num_1 == 0 and\
           biggest % num_2 == 0:
            return biggest
        biggest += 1


print(find_l_c_m(5, 7))

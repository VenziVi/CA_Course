# 7. Write a python program to find h.c.f. of two numbers
#
# For any two numbers that are inputs given by the user, we have to calculate and print the h.c.f. of that numbers.
# Case1: If the user inputs the numbers 4 and 6.
#
#
#             then the output should be ‘2’.
#
# Case2: If the user inputs the numbers 5 and 7.
#
#             then the output should be ‘1’.

def find_h_c_f(num_1, num_2):
    smallest = num_1 if num_1 < num_2 else num_2

    while smallest > 0:
        if num_1 % smallest == 0 and\
           num_2 % smallest == 0:
            return smallest
        smallest -= 1


print(find_h_c_f(35, 15))

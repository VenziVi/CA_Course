# 5. Write a program that check given an array of integers is monotonic or not.
# A = [6, 5, 4, 4]
# B = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
# C = [1, 1, 2, 3, 7]
# Output:
# True
# False
# True


def is_monotonic(lst):
    return (all(lst[i] <= lst[i + 1] for i in range(len(lst) - 1)) or
            all(lst[i] >= lst[i + 1] for i in range(len(lst) - 1)))


a = [6, 5, 4, 4]
b = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
c = [1, 1, 2, 3, 7]
print(is_monotonic(a))
print(is_monotonic(b))
print(is_monotonic(c))
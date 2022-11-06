# 1. Write a function that prints all duplicate items from a given list

# Input: [10, 20, 30, 30, 60, 60, 40, 30, 20, 70, 80]
# Expected Output: -
#
# [20, 30, 60]


def print_duplicated_items(lst: list):
    result = []
    for i, num in enumerate(lst):
        if num in lst[:i] or num in lst[i+1:]:
            if num not in result:
                result.append(num)
    print(result)


input = [10, 20, 30, 30, 60, 60, 40, 30, 20, 70, 80]
print_duplicated_items(input)

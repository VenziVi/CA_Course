# 3. Write a program to iterate a given list and count the occurrence of each
# element and create a dictionary to show the count of each element.

# Input : [11, 45, 8, 11, 23, 45, 23, 45, 89]
# Output : {11: 2, 45: 3, 8: 1, 23: 2, 89: 1}

def count_occurrence(inp: list):
    result = {}
    for num in inp:
        if result.get(num) == None:
            result[num] = 1
        else:
            result[num] += 1

    return result


inp = [11, 45, 8, 11, 23, 45, 23, 45, 89]
print(count_occurrence(inp))
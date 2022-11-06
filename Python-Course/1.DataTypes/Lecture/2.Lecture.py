print("  123.45E-45".strip().lower().partition('e'))
print("   the quick brown fox ....".replace("quick", "lazy").upper().split())

print("-------------------------------")

ages_list = [14, 56, 23, 43, 17, 33]

print(ages_list)
print(type(ages_list))

code_academy_name_as_list = list("CodeAcademy")
print(code_academy_name_as_list)

random_list = [25, "ads", 2.45, "a"]
print(random_list)

print("-------------------------------")

list_one = [2, 5, 8, 7]
print(list_one[-2])

print("-------------------------------")

bacon = ["h", "e", "l", "l", "o"]
print(bacon[::-1])
print(bacon[::1])
print(bacon[::2])
print(bacon[:4:2])

print("-------------------------------")

b = [1, 2, 3, 4, 5, 6]
b[0:0] = [7, 8, 9]
print(b)
b[0:2] = []
print(b)

print("-------------------------------")

spam = [1, 2, 3, 4]
spam.append(7)
print(spam)
spam.append("c")
print(spam)
spam.append([7, 4, 2, 0])
print(spam)

for value in spam:
    print(spam.index(value), value)

for index, value in enumerate(spam):
    print(index, value)

spam.clear()
print(spam)

print("-------------------------------")

newList = [40 + x for x in range(10, 35, 5)]
print(newList)

simple_comprehension = [x for x in range(10)]
print(simple_comprehension)

odd_simple_comprehension = [x for x in range(10) if x % 2 != 0]
print(odd_simple_comprehension)

print("-------------------------------")

some_list = [2, 5, 2, 3, 7, 2, 2]
print(some_list.count(2))

some_list.extend([5, 9, 7])
print(some_list)

print(some_list.index(7))
print(some_list.index(7, 1, 6))
print(some_list.index(7, 3))

print("-------------------------------")

jam = [2, 5, 4, 3, 7]
jam.insert(3, 255)
jam.insert(33, 122)
jam.insert(-1, 25)
print(jam)

print(jam.pop())
print(jam)
print(jam.pop(3))
print(jam)
print(jam.pop(-1))
print(jam)

print("-------------------------------")

list_to_sort = [5, 2, 8, 9, 4, 1]
list_to_sort.sort()
print(list_to_sort)

list_to_sort.sort(reverse=True)
print(list_to_sort)

list_to_sort.sort()

print("-------------------------------")

matrix = [
    [4, 5, 6],
    [2, 6, 1],
    [8, 4, 2],
]

matrix.sort(key=lambda item: item[1])
print(matrix)

matrix.sort(key=lambda item: item[1], reverse=True)
print(matrix)


print(sorted(matrix, key=lambda item: item[1]))

matrix[0].sort()
matrix[1].sort()
matrix[2].sort()
print(matrix)

print("-------------------------------")

matrix_copy = matrix.copy()
print(matrix_copy)

print(len(matrix_copy))

print("-------------------------------")

print(9 in list_to_sort)

print(list_to_sort.index(9))

print("-------------------------------")

stack = [2, 5, 7, 9]
stack.remove(5)
print(stack)
del stack[0]
print(stack)
del stack[:]
print(stack)
del stack

print("-------------------------------")

coordinates = (45.678, 24.324)
print(coordinates)
print(type(coordinates))

x, y = coordinates
print(x, y)

cord2 = (22, 77.45)

comb = cord2 + coordinates

print(comb)
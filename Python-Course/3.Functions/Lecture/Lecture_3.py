
def print_values(name, age):
    print(f"{name} is {age} years old.")

print_values("Alex", 35)

print("--------------------2------------------------")

def func_1(*values):
    for value in values:
        print(value)

func_1("some", "randome", "values")

print("----------------------3----------------------")

def calculation(a, b):
    return a + b, a - b

res = calculation(40, 10)
print(res)

print("---------------------4-----------------------")

def show_employee(name, salary=9000):
    print(f"{name} with salary: {salary}")

show_employee("Ivan")
show_employee("Asen", salary=9005)


print("--------------------5------------------------")

def bump_sum(a, b):

    def add():
        return a + b

    return add()

def add_5(a, b):
    return bump_sum(a, b) + 5


print(add_5(2, 3))

print("---------------------6-----------------------")

def rec_add(num):
    return 1 if num == 1 else num + rec_add(num - 1)


print(rec_add(10))

print("----------------------7----------------------")

new_function = print_values
new_function("Stoqn", 44)

print("-----------------------8---------------------")

def gen_list(i, j):
    while i <= j:
        if i % 2 == 0:
            yield i
        i += 1

print(list(gen_list(4, 30)))

print("----------------------9----------------------")

def find_max(items):
    if len(items) == 0:
        return

    items.sort(reverse=True)
    return items[0]

print(find_max([12, 5, 46, 96, 34]))



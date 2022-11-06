import string

print("---------------------------------------------")

def scope_test():
    def do_local():
        spam = "local spam"

    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal spam"

    def do_global():
        global spam

        spam = "global spam"

    spam = "test spam"

    do_local()
    print("after local assignment:", spam)
    do_nonlocal()
    print("after nonlocal assignment:", spam)
    do_global()
    print("after global assignment:", spam)

scope_test()
print("In global scope", spam)

print("---------------------------------------------")

def minus_five(num):
    return lambda num: num - 5

minus_number = minus_five(5)
print(minus_number(10))

print("---------------------------------------------")

def is_odd(num):
    return num % 2 != 0

print(is_odd(5))

print("---------------------------------------------")

def camel_to_any_case(text, separator="_"):
    result_text = []
    result_text.append(text[0].lower())

    for letter in text[1:]:
        if letter in (string.ascii_uppercase):
            result_text.append(separator)

        result_text.append(letter.lower())

    return "".join(result_text)

print(camel_to_any_case("ConvertStringToSnakeCase"))

print("---------------------------------------------")

def power(num, exp):
    return 1 if exp < 1 else num * power(num, exp - 1)

print(power(8, 3))

print("---------------------------------------------")

def subgen(x):
    for i in range(x):
        yield i

def gen(y):
    yield from subgen(y)

for q in gen(6):
    print(q)

print("---------------------------------------------")

def first_n(n):
    num = 0
    while num < n:
        yield num
        num += 1

print("---------------------------------------------")

def endless_number_gen():
    num = 0
    while True:
        yield num
        num += 1

for n in endless_number_gen():
    if n == 9:
        break
    print(n)

print("---------------------------------------------")

for x in ("Bom dia" for i in range(3)):
    print(x)

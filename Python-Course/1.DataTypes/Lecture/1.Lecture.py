import sys
from decimal import Decimal



name = "Venci"
print(id(name))
print(type(name))

if isinstance(name, str):
    print("i am a real string")
else:
    print("i am not a real string")

print("-------------------")

bags_count = 15
print(type(bags_count))
print(bags_count)

print("-------------------")

num_A = 38
num_B = 23

print(num_A + num_B)
print(num_A - num_B)
print(num_A / num_B)
print(num_A * num_B)
print(num_A // num_B)
print(num_A % num_B)
print(-num_A)
print(divmod(num_A, num_B))

print("-------------------")

a = 0b100110111
print(a)
b = 0o177
print(b)
c = 0o377
print(c)
d = 0xdeadbeef
print(d)
e = 0b_1110_0101
print(e)

print("-------------------")

print(type(9 / 2))
print(9 / 2)
print(type(9 // 2))
print(9 // 2)

print("-------------------")
N = 16
D = 3

N = D * (N // D) + (N % D)

print(N % D);

print("-------------------")

z, x = divmod(7, 3)
print(z)
print(x)

print("-------------------")

print(4 ** 4)
print(25 ** 1/2)

print("-------------------")

print(bin(2568))

print("-------------------")

print(int(0b101000001000))

print("-------------------")

c = 3 + 6j
print(type(c))
print(c)

print("-------------------")

base_coef = 4.5
print(type(base_coef))
print(base_coef)

print("-------------------")

coef_multi = 2
print(base_coef * coef_multi)
print(base_coef * coef_multi == 9.0)
print(base_coef * 3 == 13.5)

print("-------------------")

print(sys.float_info)
print('\n'.join(str(sys.float_info).split(', ')))

print("-------------------")

print(round(12345, -2))

print("--------------important")

num = 25
num1 = num
num1 += 5

print(num, num1)

print("-------------------important")

price = Decimal("6.5")
print(type(price))
print(price)

print(Decimal("2.1") + price)
print(2.1 + 6.5)

print(Decimal(4.2), Decimal("4.2"))

print("-------------------")

name = "Venc'i"
print(type(name))
print(name)

print("-------------------")

print(name.upper())
print(name.endswith("i"))
print(name.startswith("D"))
print(len(name))
print(name.__len__())
print(name.zfill(10))
print(sys.getsizeof(name))
print(name.__sizeof__())

print("-------------------")

age = 35
name = "Venci"
print(f"{name} is {age} age old")
print("{0} is {1} age old.".format(name, age))
print("{n} is {a} age old.".format(n="Gosho", a=28))
print("I love Wikiversity!", end="\n")

print("-------------------")
a = 100
name = "something"
print("{:^{fill}}".format(name, fill=100))
print("{:<100}".format(name))
print("{:>100}".format(name))
print(name.center(a))
print(name.rjust(a))

print("-------------------")

name = "I8086"
date = 2014
print("Copyright (c) %s %d" % (name, date))
print("alabala %d" % 1234)

print("-------------------")

a = ("deヿfㇿg").encode()
print(a)
print(len(a))

print("-------------------")
a = "1.5"
print("1234".isnumeric())
print("asd454qds".isalnum())
print("asd as$3334".isalnum())
print(a.isdigit())

print("-------------------")

name = "Ventsislav"
print(name[1::2])

print("-------------------for-statement")

str = "codeAcademy"

for char in str:
    print(char)

print("------------------append")

msg = ["start:"]

for x in range(10):
    msg.append(f"message el {x}")

msg.append("end!")
msg_str = "\n".join(msg)
print(msg_str)

print("-------------------")

var_1 = "I write code from"
var_2 = 24
var_3 = "months"

var_4 = f"{var_1} {var_2} {var_3}"

print(var_4)

print("-------------------")

print(" 123   gdgf  5625".split())


print("-------------------")
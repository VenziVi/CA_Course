a = 0
while a < 10:
    b = 0
    while b < 10:
        c = 0
        while c < 10:
            print("{}{}{}".format(a, b, c,))
            pass
            c += 1
        b += 1
    a += 1
else:
    print("normal termination")

print("---------------------------------------")

a = 0
flag = True

while a < 10 and flag:
    b = 0
    while b < 10 and flag:
        c = 0
        while c < 10:
            print("{}{}{}".format(a, b, c,))
            if a ==2 and b == 4 and c == 3:
                flag = False
                break
            c += 1
        b += 1
    a += 1
else:
    print("normal termination")

print("Flag = ", flag)

print("---------------------------------------")

for num in range(1, 8):
    print(num % 2)
else:
    print("Success!")

print("---------------------------------------")

ages_one = [12, 15, 17, 18, 15, 26]
ages_two = [9, 17, 20, 14, 13, 28]

for age, age_two in zip(ages_one, ages_two):
    print(age, age_two)

print("---------------------------------------")

for berry in (1, 2, 3, 4, 5, 6, 7, 8):
    print(berry % 4)
    if berry % 4 == 0:
        break
else:
    print("for loop didn't end!")

print("---------------------------------------")

a = [0, 1, -2, 3, -4, -5, -6, -7, 8, -9, -10, 11, -12]

for p, c in zip(range(len(a)), a):
    print("a[{}] = {}".format(p, c))

print("---------------------------------------")
names = ["Jhon", "Bill", "Jack"]
ages = [21, 25, 35]
weights = [165, 132, 175]
heights = [[5, 8], [4, 1], [6, 1]]

for name, age, weight, height in zip(names, ages, weights, heights):
    feet, inches = height
    print("{}: age = {} years; weight = {} lbs; height = {} ft {} in".format(name, age, weight, feet, inches))

print("---------------------------------------")

try:
    print(spam)
except:
    print("spam isn't defined!")

print("---------------------------------------")

try:
    spam = 7
    print("I have %d cans of spam!" % spam)
except:
    print("Error")
else:
    print("OK")


print("---------------------------------------")

try:
    print(spamm)
except:
    print("Error")
else:
    print("OK")
finally:
    print("Finish up now..!")

print("---------------------------------------")

with open("hello.txt", "r") as file:
    print(file.read())

print("---------------------------------------")
#user_age = input("Enter your age: ")
#user_name = input("Enter your name: ")
#print(user_age, user_name)

#user_details = input("Enter details: ").split(" ")
#print(", ".join(user_details))

print("---------------------------------------")

import sys
import os

print("Line 1e to stdout", file=sys.stderr)
sys.stderr.write("line 2e to stderr\n")
sys.stderr.flush()
os.write(2, b"line 3e to stderr\n")


from decimal import Decimal

print(bool(""))
print(bool(" "))
print(bool("Code"))
print(bool({}))
print(bool([]))

print("------------------------------------------------")

for A in True, False:
    for B in True, False:
        for C in True, False:
            b1 = (A and B) or C
            b2 = A and (B or C)
            if b1 != b2:
                print('''
                    for A = {}, B = {}, C ={}
                    (A and B) or C = {}
                    A and (B or C) = {}
                    '''.format(A, B, C, b1, b2))

print("------------------------------------------------")

ages = {14, 15, 14, 15, 17, 18, 16}
print(type(ages))
print(ages)

for age in ages:
    print(age)

print("------------------------------------------------")

b1 = set("12345")
print(b1)
b2 = {"12345"}
print(b2)
print(len(b1))
print("3" in b1)

print("------------------------------------------------")

print(ages)
ages.add(20)
print(ages)
ages.add(17)
print(ages)

print("------------------------------------------------")

print(ages.pop())
print(ages)
print(ages.pop())
print(ages)

print("------------------------------------------------")

ages.discard(17)
print(ages)
ages.remove(18)
print(ages)
ages.discard(18)

print("------------------------------------------------")

sh_ages = ages
dp_ages = set(ages)
print(ages)
print(dp_ages)
print(sh_ages)
sh_ages.add(222)
dp_ages.add(5)
ages.add(23)
print(ages)
print(dp_ages)
print(sh_ages)

print(sh_ages == dp_ages)
print(ages == dp_ages)
print(ages == sh_ages)

print("------------------------------------------------")

print({x*x%7 for x in range(-234, 79)})
print([x*x%7 for x in range(-234, 79)])

a = {x for x in 'abracadabra' if x in 'abcrmgx'}
print(a)

print("------------------------------------------------")

set1 = {"re", "pe", "ce"}
set2 = {"pe", "me", "ka", "de"}
set3 = {"ga", "df", "gq"}

print(set1.isdisjoint(set2))
print(set1.isdisjoint(set3))

print("------------------------------------------------")

print({"a", "b", "c"}.issubset({"a", "b", "c", "d"}))
print({"a", "b", "c"}.issubset(["a", "b", "c", "d"]))
print({"a", "b", "c"}.issubset(["a", "b", "d"]))
print({"a", "b", "c"} <= {"a", "b", "c"})
print({"a", "b", "c"} <= {"a", "b", "c", "d"})
print({"a", "b", "c", "z"} < {"a", "b", "c", "d"})

print("------------------------------------------------")

print({"a", "b", "c", "h"}.symmetric_difference({"a", "b", "c", "d", "f"}))
print({"a", "b", "c", "h"} ^ {"a", "b", "c", "d", "f"} ^ {"a", "z"} ^ {"q", "c"})

print("------------------------------------------------")

print({"a", "b", "c", "h"}.union({"a", "b", "c", "d", "f"}))
print({"a", "b", "c", "h"}.union({"a", "b", "c", "d", "f"}, ["q", "t", "x"], "asdf"))

print({"a", "b", "c", "h"} | ({"a", "b", "c", "d", "f"}))
print({"a", "b", "c", "h"} | {"a", "b", "c", "d", "f"} | set(["q", "t", "x"]) | set("asdf"))


print("------------------------------------------------")

s_ages = {14, 15, 17, 19, 22}
p_ages = {15, 16, 23, 43, 25}

print(s_ages, "| ", p_ages, s_ages | p_ages)
print(s_ages, "& ", p_ages, s_ages & p_ages)
print(s_ages, "^ ", p_ages, s_ages ^ p_ages)
print(s_ages, "- ", p_ages, s_ages - p_ages)

print("------------------------------------------------")

print(s_ages)
s_ages.intersection_update({14, 15}, {16, 17}, {25, 30})
s_ages &= {14, 15}
s_ages &= {16, 17}
s_ages &= {25, 30}
print(s_ages)

print("------------------------------------------------")

print(p_ages)
p_ages.difference_update({14, 15}, {16, 17}, {25, 30})
p_ages -= {14, 15}
p_ages -= {16, 17}
p_ages -= {25, 30}
print(p_ages)

print("-----------------1.task------------------------")

name = "Ivan"
age = 25
account_amount = Decimal("125.25")
standard_dev = 12.48
is_student = True

print("-----------------2.task------------------------")

student_names = []
student_register = dict()
student_names_unique = set()

print("-----------------3.task------------------------")
student_names.append(name)
student_names.append("Peter")
student_names.append("Alex")

student_register[255] = {
                        "Name": "Ivan",
                        "Course": 4,
                        "Age": 18,
                        "Grades": {
                            "Math": 3.55,
                            "History": 4.56,
                        }}

student_register[257] = {
                        "Name": "Emo",
                        "Course": 3,
                        "Age": 16,
                        "Grades": {
                            "Math": 4.55,
                            "History": 3.56,
                        }}


student_names_unique.add(name)
student_names_unique.add("Ivan")
student_names_unique.add("Peter")

print("-----------------4.task------------------------")

student_names.remove("Ivan")
student_register.pop(255)
student_names_unique.discard("Maria")

print("-----------------5.task------------------------")

print(student_names)
print(student_register)
print(student_names_unique)
print(student_register.get(318))

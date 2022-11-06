from collections import Counter

fruits = {
    "green_apple": "green",
    "banana": "yellow",
}

print(type(fruits))
print(fruits)
print(fruits["banana"])

print("--------------------------------------")

student_info = {
    "name": "Ivan",
    "age": 20,
    "courses": ["Bulgarian", "Math"],
    "family": {
        "members": 5,
        "brothers": [],
        "sisters": [("Mihaela", 12)],
    }
}
print(len(student_info))
print(student_info)
print(student_info["courses"])
print(student_info["family"]["sisters"])
print(student_info.get("age"))
print(student_info.pop("age"))
print(student_info)

print(student_info.get("age"))
print(student_info.get("age", "no entry"))

print(student_info.pop("age", "no entry"))

print(student_info.get("family").get("sisters"))

print(len(student_info))

print("--------------------------------------")

fruits["banana"] = "brown"
print(fruits["banana"])
fruits["carrot"] = "orange"
print(fruits)

fruits.update(green_apple="blu")
fruits.update(blueberry="violet")
print(fruits)

print("--------------------------------------")

a = {"one": 1, "two": 2, "three": 3}
a.update(four=4) #**kwarg
a.update({"five": 5}) #dict
a.update([("six", 6)]) #lis
a.update({("seven", 7)}) #set
a.update({"eight": 8}, nine=9) #dict and **kwarg

print(a)

print(a.popitem())
current_fruit, color = fruits.popitem()
print(current_fruit, color)

print("--------------------------------------")

cmp = {"blue": 0, "red": 1, "green": 2} == {"green": 2, "blue": 0, "red": 1} == {"blue": 0, "green": 2, "red": 1}
print(cmp)

print("--------------------------------------")

phones = {"Jack": 25686, "John": 7825625, "Sofi": 123569}
pairs = phones.items()
print(pairs)
print(len(pairs))

pairs = list(phones.items())
print(pairs)

names = phones.keys()
print(names)

numbers = phones.values()
print(numbers)

#names = list(phones.keys())
#print(names)

del phones["Sofi"]
print(numbers)
print(names)

print("--------------------------------------")

for person, phone in phones.items():
    print(person, phone)

for person in phones.keys():
    print(person)

for phone in phones.values():
    print(phone)

print("--------------------------------------")

a = [1, 4, 3, 7, 4, 7, 2, 7, 9, 7]
c = Counter(a)
print(c)

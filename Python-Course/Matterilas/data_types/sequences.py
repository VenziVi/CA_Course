import string
from string import Template

print(string.ascii_letters)
print(string.ascii_uppercase)
print(string.digits)
print(string.hexdigits)
print(string.octdigits)


name = "Pesho"
print(type(name))
print(name[1::2])
print(8 * "x")

english_name = "John O\"reilly"
escaping = "John O\\reilly"
escaping_single_quotes = 'John O\'reilly'
escaping_single_quotes_tripple_quotes = """John O'rei"lly"""
print(escaping_single_quotes_tripple_quotes)
multiline_string = """kjaslkdjalskd
jaslkdjalsda;sd
jalksjdalsdl;askd
kajslkdjalksjdlaksjd
kjaslkjdlaksjdlaksjd"""
multiline_string_option_two = (
    "John O\"reilly "
    "is chosen for "
    "multiline string example"
)
print(multiline_string_option_two)

string_length = 32
formatted_sentence = (
    f"This is example for printing {string_length} sized string and formula. "
    "\n This is regular sentence. "
    f"\nThis is example for formula within string {5 * 5 * 5}."
    f"\nExample for executing regular function within formatted string {len(multiline_string_option_two)}"
)
print(formatted_sentence)

name += str(31)

message = ["Header"]

for x in range(100):
    message.append(f"Message el {x}")

message_as_str = "\n".join(message)
print(message_as_str)


# print(name)  # Hm, this is possible, but string is immutable?
# print(name.title())
# print(name.capitalize())
# print(name.isalnum())
# print(name.isalpha())
# print(name.isdigit())
# print(name.zfill(5))
# print(message_as_str.split())


# formatted string
sentence = "{name} is {aged} and lives in {living_place}."
print(sentence.format(name="Pesho", aged=28, living_place="Sofia"))
# >>> Pesho is 28 and lives in Sofia.

sentence_positional_example = "{0} is {1} and lives in {2}.".format("CodeAcademy", "8", "Sofia")
print(sentence_positional_example)

code_academy_name = "CodeAcademyBG"

custom_spacing = 250
print(name.center(custom_spacing))
print(name.ljust(custom_spacing))
print(name.rjust(custom_spacing))
print("{:^{fill}}".format(code_academy_name, fill=100))
print("{:<100}".format(code_academy_name, 24))
print("{:>100}".format(code_academy_name))

print(name.startswith('N'))
print(name.endswith('M'))

name_as_array = list(name)
print(name_as_array)

name = ''.join(name_as_array)

print("int: {0:d};  hex: {0:x};  oct: {0:o};  bin: {0:b}".format(42))

code_academy = "CodeAcademyString"
print(code_academy[1:5])

template = Template("$who likes $what")
print(template.substitute(who=name, what="Programming languages"))

dict_args = dict(what="Football")

template_safe = Template("$who likes $what")
# print(template_safe.substitute(dict_args))
print(template_safe.safe_substitute(dict_args))

# define a simple ages list variable
ages_list = [14, 15, 14, 15, 16, 17, 8, 19, 18, 35]
ages_adults_list = [40 + x for x in range(10, 35, 5)]
simple_list_comprehension = [x for x in range(10)]
simple_list_comprehension_simple_formula = [x + 1 for x in range(10)]
simple_list_comprehension_simple_if = [x for x in range(10) if x % 2 != 0]

simple_list_comprehension_as_for_loop_iteration = []
for x in range(10):
    simple_list_comprehension_as_for_loop_iteration.append(x)

name_as_list = list('CodeAcademy')
last_element = ages_list.pop()
is_twenty_in_ages_list = 22 in ages_list
print(is_twenty_in_ages_list)

list_one = [1, 2, 3, 4, 5]
print(list_one[-1], list_one[-2], list_one[-6])

list_a = [1, 2, [4, 5, 6]]
list_b = list(list_a)

list_a[2][0] = 8
print(list_a)
print(list_b)


print("Last element: {0}".format(last_element))
print("First element: {0}".format(ages_list[0]))

index_of_15 = ages_list.index(15)
print(index_of_15)

print("Length of ages_list: ", len(ages_list))

print("Count of 15 in ages_list ", ages_list.count(15))

# print("Index of 10001 in ages_list, ", ages_list.index(1001))

ages_list.sort()
print("Sorted version of ages_list: ", ages_list)

print("Sorted version of ages_adults_list: ", sorted(ages_adults_list, reverse=True))


# add new age to ages_list
ages_list.insert(20, 2)
ages_list.append(99)

# remove age from ages_list
ages_list.remove(14)

sliced_ages = ages_list[1:5]

# iterate over list
for age in ages_list:
    print(age)

for age in ages_list + ages_adults_list:
    print(age)


matrix_example = [
    [1, 7, 9],
    [4, 5, 6],
    [7, 8, 9],
]


print(len(matrix_example))
matrix_shallow_copy = matrix_example.copy()

# matrix_example.sort(key=lambda item: item[1], reverse=True)
print(sorted(matrix_example, key=lambda item: item[1]))

for matrix_el in matrix_example:
    print(matrix_el[-1], matrix_el[1])

for name, age, city in [("CodeAcademy", 8, "Sofia"), ("Name2", 12, "Sofia"), ("Name3", 15, "Sofia")]:
    matrix_example.append([name, age, city])

print(matrix_example)
matrix_example_as_comprehension = [[row[i] for row in matrix_example] for i in range(3)]
print(matrix_example_as_comprehension)

del matrix_example_as_comprehension[-1]

print("After deletion ", matrix_example_as_comprehension)


coords = (45.2545, 26.5874)
coords2 = (47.2545, 22.5874)
coords_combined = coords + coords2

coords3 = (45.2545, 26.5874)
coords4_list = [47.2545, 22.5874]
coords_combined_between_list_and_tuple = coords3 + tuple(coords4_list)
# coords += (487.212, 222.222)
print(coords)  # The result is new tuple coords created, not just mutated the original

print("Coord one ", coords[0])
print(len(coords))

x, y = coords
print(x, y)

person_data = (30, "Name", "Address")
person_age, person_name, person_address = person_data

for coord in coords:
    print(coord)


transactions_data = "4124124_53453_AJKAHS73841|||9898_150_AJKAHS7398547|||999_456_BSFDHS73841"
transactions = [transaction.split("_") for transaction in transactions_data.split("|||")]


# Stack example with list
stack = [3, 4, 5, 7]
stack_element = stack.pop()
stack.append(8)

# Queue example with list
from collections import deque
list_queue = deque([3, 4, 5, 7])
list_queue.append(9)
list_queue.popleft()


# Add del example in Presentation
# Add .sort() and sorted() in presentation


import csv
import math
import os.path
import re
from pprint import pprint
from settings.testing import INPUT_DIR

def validate_student_data_row(row):
    '''
    Input : ["George", "123123" , "10", "3"]
    Output: True
    :param list:
    :return: is row valid:
    '''
    if len(row) != 4:
        return False
    if not row[2].isdigit() or int(row[2]) < 0:
        return False
    if not row[3].isdigit() or int(row[3]) < 0:
        return False
    return True


def get_students_data():
    student_data = {}

    with open(os.path.join(INPUT_DIR, 'students_data.csv'), 'r') as source:
        reader = csv.reader(source)

        # Finish the function by adding code that would extract the students data from the file.
        # We only need valid students_data, i.e. from filled rows.
        for row in reader:
            if not validate_student_data_row(row):
                continue
            student_name, student_id, score, remaining_exams = row
            student_data[student_id] = {"first_name": student_name,
                                        "score": int(score),
                                        "remaining_exams": int(remaining_exams)}

    return student_data


def get_sqrt(number):
    # This function is not working, can you fix it?
    return math.sqrt(number)


def get_top_three_students():
    # 1. Read the students_data.csv
    # 2. Collect the students data
    # 3. Return the top 3 students, ranked by current result.
    student_data = get_students_data()
    result = []

    for student in sorted(student_data, key=lambda x: (student_data[x]["score"]), reverse=True)[:3]:
        result.append(student_data[student]["first_name"])

    return result


def validate_input_data(user_name, user_age):
    if len(user_name) < 3:
        return False
    if not user_age.isdigit() or 1 < int(user_age) > 100:
        return False
    return True

def set_user_name_age(user_info):
    '''
    Set user_name and user_age from input list,
    if one is missing returns empty string for user_name
    and zero for user_age
    input: ["Ivan", "25"]
    output: user_name = "Ivan"
            user_age = "25"
    :params list:
    :return: user_name, user_age
    '''
    if len(user_info) == 2:
        user_name, user_age = user_info
    else:
        user_name = ""
        user_age = 0
    return user_name, user_age

def parse_input_data(user_input):
    '''
    Check if status is present,
    if not set status to an empty string.
    Calls set_user_name_age function to set user_name and user_age
    input: "Georgi 28, VIP"
    output: user_name = "George"
            user_age = "28"
            user_status = "VIP"
    :param string:
    :return user_name, user_age, user_status:
    '''
    if ", " in user_input:
        user_info = user_input.split(", ")
        user_status = user_info[1]
        user_name, user_age = set_user_name_age(user_info[0].split(" "))
    else:
        user_name, user_age = set_user_name_age(user_input.split(" "))
        user_status = ""

    return user_name, user_age, user_status

def set_entry_checker():
    # Ask for user's data: First name, age and VIP status.
    # If user's age is under 18, do not allow user to proceed
    # If user's age is between 18 - 25, allow them to stay up to 11pm
    # If group 18_25 has more than 10 users, do not allow user to enter.
    # If user is aged over 25, welcome them without any additional conditions.
    # As an output print-out the users count from each group, and also print the VIPs
    # Example input: (Georgi 28, VIP) OR (Alex 25)
    users_data = {"18_25": {}, "over_25": {}}
    id = 0

    while True:
        user_input = input("Enter first name, age and status: ")
        if user_input == "exit":
            break

        user_name, user_age, user_status = parse_input_data(user_input)

        if not validate_input_data(user_name, user_age):
            print("Invalid input data!")
            continue

        age = int(user_age)

        if  age < 18:
            print("You are too young!")
        elif age <= 25:
            if len(users_data["18_25"]) < 11:
                id += 1
                print("You can stay up to 11pm.")
                users_data["18_25"][id] = {"name": user_name, "age": age, "status": user_status}
            else:
                print("No vacancy!")
        else:
            id += 1
            users_data["over_25"][id] = {"name": user_name, "age": age, "status": user_status}


    for group_name, group in users_data.items():
        print(f"{len(group)} users in group {group_name}")
        for user in group.values():
            if user['status'] == "VIP":
                print(f"VIP - {user['name']}")


def get_even_numbers(array):
    # Finish the function by adding code that would print out only the even numbers.
    [print(num) for num in array if num % 2 == 0]


def get_is_password_valid():
    # Ask for user's password.
    # Check user's password against the following conditions:
    # At least 6 symbols, and maximum of 32 symbols.
    # At least 1 upper case letter.
    # At least 1 symbol.
    # hint: use the re library.
    password_regex = r"^(?=.*?[A-Z])(?=.*?[#?!@$%^&*-]).{6,32}$"
    user_password = input("Enter password: ")

    while not re.fullmatch(password_regex, user_password):
        user_password = input("Enter valid password: ")

    print("Password is valid.")


print("---------------1.get_students_data----------------")

pprint(get_students_data())

print("---------------2.get_sqrt----------------")

print(get_sqrt(16))

print("---------------3.get_top_three_students----------------")

print(get_top_three_students())

print("---------------4.set_entry_checker----------------")

set_entry_checker()

print("---------------5.get_even_numbers----------------")

get_even_numbers([1, 5, 3, 2, 7, 8, 4, 17, 64, 28, 99])

print("---------------6.get_is_password_valid----------------")

get_is_password_valid()

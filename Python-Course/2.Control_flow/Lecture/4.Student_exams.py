import csv
import os
import random

from settings.testing import BASE_DIR

NEEDED_AVG_POINTS = 80
MAX_RETAKES = 3
AVG_INIT_VALUE = 0
RANDOM_MIN_RANGE = 50
RANDOM_MAX_RANGE = 95


def print_passed_students(students_data):
    for student_id, student_info in reversed(students_data.items()):
        if student_info["avg"] >= NEEDED_AVG_POINTS:
            print(f"Student {student_id} passed with {student_info['avg']} average result.")


def print_failed_students(students_data):
    for student_id, student_info in students_data.items():
        if student_info["avg"] < NEEDED_AVG_POINTS:
            print(f"Student {student_id} NOT passed with {student_info['avg']} average result.")


def calculate_student_avg_grade(student_info):
    student_info["avg"] = sum(student_info["exams"].values()) / len(student_info["exams"])


def set_students_data(reader):
    students_data = {}

    for row in reader:
        student, exam_id, grade = row

        if not exam_id.isdigit():
            continue

        student_id = int(student.split(" ")[1])
        if student_id not in students_data:
            students_data[student_id] = {"avg": AVG_INIT_VALUE, "exams": {}}

        students_data[student_id]["exams"][exam_id] = int(grade)

    return students_data


def read_student_data():
    INPUT_DIR = os.path.join(BASE_DIR, "test_files", "input")

    with open(os.path.join(INPUT_DIR, "students_exams.csv"), "r") as source_file:
        reader = csv.reader(source_file)
        students_data = set_students_data(reader)

    return students_data


def retake_current_exam(student_info, exam_id):
    retake_count = 0

    while student_info["exams"][exam_id] < NEEDED_AVG_POINTS and retake_count <= MAX_RETAKES:
        student_info["exams"][exam_id] = random.choice(range(RANDOM_MIN_RANGE, RANDOM_MAX_RANGE))
        retake_count += 1


def retake_exams(student_info):

    for exam_id in student_info["exams"].keys():
        retake_current_exam(student_info, exam_id)
        calculate_student_avg_grade(student_info)

        if student_info["avg"] >= NEEDED_AVG_POINTS:
            break


def get_student_data():

    students_data = read_student_data()

    for student_info in students_data.values():
        calculate_student_avg_grade(student_info)

        if student_info["avg"] < NEEDED_AVG_POINTS:
            retake_exams(student_info)

    print_passed_students(students_data)
    print_failed_students(students_data)


if __name__ == "__main__":
    get_student_data()
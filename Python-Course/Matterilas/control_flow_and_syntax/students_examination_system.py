import csv
import os
from collections import defaultdict

from settings.testing import BASE_DIR

INPUT_DIR = os.path.join(BASE_DIR, "test_files", "input")

students_dict = defaultdict(
    lambda: {"passed_exams": {}, "failed_exams": {}, "avg_score": 0}
)

with open(os.path.join(INPUT_DIR, "students_exams.csv"), "r") as source_file:
    reader = csv.reader(source_file)

    for student, exam, score in reader:
        if student == "student":
            continue
        if int(score) >= 80:
            students_dict[student]["passed_exams"][exam] = int(score)
        else:
            students_dict[student]["failed_exams"][exam] = int(score)
        students_dict[student]["avg_score"] = (sum(
            students_dict[student]["passed_exams"].values()
        ) + sum(students_dict[student]["failed_exams"].values())) // 10


for student_data in students_dict.values():
    if student_data["avg_score"] >= 80:
        continue
    # For every exam in failed_exams:
    # while 3 attempts are not taken, go to retake
    # if first retake is over or equal 80 check the session result
    # if session is passed, continue with next student
    # if not, go to retake

# Print out result for all students, starting with those who passed the session with TOP score

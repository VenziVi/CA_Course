from Lecture_2_Student import Student

class YearsPassed:
    def __init__(self, years_passed):
        self.years_passed = years_passed

    def pass_year(self):
            self.years_passed += 1


class BachelorStudent(Student, YearsPassed):
    def __init__(self, gender, age, height, weight, name, years_passed):
        Student.__init__(self, gender, age, height, weight, name)
        YearsPassed.__init__(self, years_passed)



b1 = BachelorStudent('male', 32, 180, 100, "Ivan", 5)
print(b1)
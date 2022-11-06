from Lecture_2_Person import Person

class Student(Person):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.occupation = "Student"
        self.courses = set()


    def add_courses(self, course):
        self.courses.add(course)


    @classmethod
    def create_from_person(cls, person_instance):
        return cls(
            person_instance.gender,
            person_instance.age,
            person_instance.height,
            person_instance.weight,
            person_instance.name,
        )

person_instance = Person("male", 36, 176, 75, "Venci")
student_one = Student.create_from_person(person_instance)
print(student_one, f"I am {student_one.occupation}")

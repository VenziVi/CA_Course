
class Person:
    def __init__(self, id, name, age):
        self.id = id
        self.name = name
        self.age = age

    def __str__(self):
        return f"{self.name} with " \
               f"id: {self.id} is {self.age} years old."


class Employee(Person):
    def __init__(self,id, name, age, experience, company):
        super().__init__(id, name, age)
        self.experience = experience
        self.company = company

    def __str__(self):
        return super().__str__() + f" Works in {self.company}" \
                                   f" with {self.experience} years of experience."


Alex = Person(78546, "Alex", 38)
print(Alex)
Ivan = Employee(123456, "Ivan", 35, 12, "SomeCompany")
print(Ivan)

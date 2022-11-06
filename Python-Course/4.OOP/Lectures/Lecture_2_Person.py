class Person:

    GENDER_OPTIONS = ('female', 'male')

    def __init__(self, gender, age, height, weight, name):
        self.__gender = self.__validate_gender(gender)
        self.age = age
        self.height = height
        self.weight = weight
        self.name = name

    def __validate_gender(self, gender):
        if gender not in self.GENDER_OPTIONS:
            raise ValueError(f"{gender} is not valid gender type!")
        return gender

    def __str__(self):
        return f"I am {self.name}"

    @property
    def gender(self):
        return self.__gender

    @gender.setter
    def gender(self, value):
        raise TypeError("Gender value is unchangeable")

    @classmethod
    def create_person(cls, * args, **kwargs):
        # Do something
        return cls(*args, **kwargs)

    @staticmethod
    def some_static_method(*args, **kwargs):
        # Do something
        pass

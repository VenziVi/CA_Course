import math


class Triangle:
    max_size = 20
    min_size = 0

    def __init__(self, side_a, side_b, side_c):
        self.__side_a = side_a
        self.__side_b = side_b
        self.__side_c = side_c

    def __str__(self):
        return f"parameter: {self.calc_perimetr()}, area: {self.calc_area()}"

    @property
    def side_a(self):
        return self.__side_a

    @side_a.setter
    def side_a(self, value):
        if value <= self.min_size or value > self.max_size:
            raise ValueError
        self.__side_a = value

    @property
    def side_b(self):
        return self.__side_b

    @side_b.setter
    def side_b(self, value):
        if value <= self.min_size or value > self.max_size:
            raise ValueError
        self.__side_b = value

    @property
    def side_c(self):
        return self.__side_c

    @side_c.setter
    def side_c(self, value):
        if value <= self.min_size or value > self.max_size:
            raise ValueError
        self.__side_c = value

    def calc_perimetr(self):
        return self.side_a + self.side_b + self.side_c

    def calc_area(self):
        perimeter = self.calc_perimetr()
        per = perimeter // 2
        result = per * (per - self.side_a) * (per - self.side_b) * (per - self.side_c)
        return math.sqrt(result)


# tr = Triangle(3, 4, 5)
# print(tr)
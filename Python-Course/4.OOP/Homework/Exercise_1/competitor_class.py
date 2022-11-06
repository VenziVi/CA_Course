from time_class import Time


class Competitor:
    """
    class Competitor represents competitor in marathon
    initialized with registration number, first_name and last name

    class attributes:
        __min_reg_number:
        __max_reg_number:
        __min_name_len:

    attributes:
        __registration_number:
            possible values between __min_reg_number and __max_reg_number
        __first_name:
            competitor first name, mst be at least __min_name_len letters long
        __last_name:
            competitor last name, mst be at least __min_name_len letters long
        __starting_time:
            class Time initialized with zero values,
            must be set with set_starting_time function when the competitor cross the start line
        __finish_time:
            class Time initialized with zero values,
            must be set with set_finish_time function when the competitor cross the finish line
        __result_time:
            class Time initialized with zero values,
            set with calculate_result_time function when the competitor cross the finish line
            or the marathon is over
    """
    __min_reg_number = 1
    __max_reg_number = 1000
    __min_name_len = 3

    def __init__(self, number: int, first_name: str, last_name: str):
        self.__registration_number = self.__validate_number(number)
        self.__first_name = self.first_name = first_name
        self.__last_name = self.last_name = last_name
        self.__starting_time = Time.init_time_class()
        self.__finish_time = Time()
        self.__result_time = Time()

    def __str__(self):
        return "| {:>7} | {:>15} | {:>15} | {:>10} | {:>10} | {:>10} |"\
                .format(self.registration_number, self.first_name, self.last_name, str(self.starting_time),
                str(self.finish_time), str(self.__result_time))

    def __validate_number(self, number: int):
        """
        validates competitor registration number
        raise ValueError if number is not valid
        :param number:
        :return int:
        """
        if number < self.__min_reg_number or number > self.__max_reg_number:
            raise ValueError("Invalid competitor number!")
        return number

    @property
    def registration_number(self):
        """
        return competitor registration number
        """
        return self.__registration_number

    @property
    def first_name(self):
        """
        return competitor first name
        """
        return self.__first_name

    @first_name.setter
    def first_name(self, value: str):
        """
        set competitor first name
        raise ValueError if first name length is smaller than __min_name_len
        :param value:
        """
        if len(value) < self.__min_name_len:
            raise ValueError(f"First name must be min {self.__min_name_len} letters long!")
        self.__first_name = value

    @property
    def last_name(self):
        """
        return competitor last name
        """
        return self.__last_name

    @last_name.setter
    def last_name(self, value: str):
        """
        set competitor last name
        raise ValueError if last name length is smaller than __min_name_len
        :param value:
        """
        if len(value) < self.__min_name_len:
            raise ValueError(f"Last name must be min {self.__min_name_len} letters long!")
        self.__last_name = value

    @property
    def starting_time(self):
        """
        return competitor start time
        """
        return self.__starting_time

    def set_starting_time(self):
        """
        set starting time with values from daytime now
        """
        self.__starting_time.set_time()

    @property
    def finish_time(self):
        """
        return competitor finish time
        """
        return self.__finish_time

    def set_finish_time(self):
        """
        set finish time with values from daytime now
        """
        self.__finish_time.set_time()

    @property
    def result_time(self):
        """
        return competitor result time
        """
        return self.__result_time

    def calculate_result_time(self):
        """
        calculate difference between finish time and start time
        set a result time with values from the calculation
        """
        hours, minutes, seconds = self.__finish_time.time_diff(self.__starting_time)
        self.__result_time.hours = hours
        self.__result_time.minutes = minutes
        self.__result_time.seconds = seconds

    @classmethod
    def create_competitor(cls, number, first_name, last_name):
        """
        create an instance from the Competitor class
        if the number is a string it will be cast to an int
        raise ValueError if number contains a non-numeric character
        :param number:
        :param first_name:
        :param last_name:
        :return class Competitor:
        """
        if isinstance(number, str):
            if not number.isdigit():
                raise ValueError("Competitor number must contains only digits!")
            number = int(number)
        return cls(number, first_name, last_name)

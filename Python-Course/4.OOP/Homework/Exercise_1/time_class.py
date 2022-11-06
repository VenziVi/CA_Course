from _datetime import datetime


class Time:
    """
    class Time represents time with hours, minutes, seconds
    initialized with zero values
    to set time attributes use setter functions for each
    or use set_time function to set attributes with daytime now values

    class attributes:
        __second_in_hour
            equals to seconds in 1 hour
            used to convert hours to seconds
        __second_in_minute
            equals to seconds in 1 minute
            used to convert minutes to seconds

    attributes:
        __hours
        __minutes
        __seconds

    """
    __second_in_hour = 3600 # Good, also you can make constants
    __second_in_minute = 60

    def __init__(self):
        self.__hours = 0
        self.__minutes = 0
        self.__seconds = 0

    def __str__(self):
        return "%02d:%02d:%02d" % (self.hours, self.minutes, self.seconds)

    @staticmethod
    def __validate_min_or_sec(value: int):
        """
        validate minutes or seconds value
        :param value:
        :return Bool:
        """
        if value < 0 or value > 59:
            return False
        return True

    @property
    def hours(self):
        """
        returns hours value
        """
        return self.__hours

    @hours.setter
    def hours(self, value: int):
        """
        set hours value
        raise ValueError if value is not valid
        :param value:
        """
        if value < 0 or value > 23:
            raise ValueError("Invalid hours value!")
        self.__hours = value

    @property
    def minutes(self):
        """
        returns minutes value
        """
        return self.__minutes

    @minutes.setter
    def minutes(self, value: int):
        """
        set minutes value
        raise ValueError if value is not valid
        :param value:
        """
        if not self.__validate_min_or_sec(value):
            raise ValueError("Invalid minutes value!")
        self.__minutes = value

    @property
    def seconds(self):
        """
        returns seconds value
        """
        return self.__seconds

    @seconds.setter
    def seconds(self, value: int):
        """
        set seconds value
        raise ValueError if value is not valid
        :param value:
        """
        if not self.__validate_min_or_sec(value):
            raise ValueError("Invalid seconds value!")
        self.__seconds = value

    def set_time(self):
        """
        set time class attributes with daytime now values
        use attributes setters
        """
        self.hours = datetime.now().time().hour
        self.minutes = datetime.now().time().minute
        self.seconds = datetime.now().time().second

    def __convert_from_seconds(self, value: int):
        """
        convert given seconds to hours, minutes, seconds
        :param value:
        :return int, int, int:
        """
        hours = value // self.__second_in_hour
        value %= self.__second_in_hour
        minutes = value // self.__second_in_minute
        seconds = value % self.__second_in_minute
        return hours, minutes, seconds

    def __convert_to_seconds(self, hours: int, minutes: int, seconds: int):
        """
        calculate and returns seconds in given hours and minutes
        :param hours:
        :param minutes:
        :return int:
        """
        return hours * self.__second_in_hour + minutes * self.__second_in_minute + seconds

    def __sub__(self, other):
        """
        defines how to use subtraction for two Time classes
        convert both times to seconds
        calculate difference
        convert and returns difference in hours, minutes, seconds
        if one of tiles is equal to 0 return 0, 0, 0
        :param other:
        :return int, int, int:
        """
        start = self.__convert_to_seconds(self.hours, self.minutes, self.seconds)
        end = self.__convert_to_seconds(other.hours, other.minutes, other.seconds)
        if start == 0 or end == 0:
            return 0, 0, 0
        difference = abs(end - start)
        return self.__convert_from_seconds(difference)

    def time_diff(self, time):
        """
        calculate the difference between two time classes
        returns ints: hours, minutes, seconds
        :param time:
        :return int, int, int:
        """
        return self - time

    @classmethod
    def init_time_class(cls):
        """
        create and return Time class instance
        """
        return cls()

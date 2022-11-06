from turtle import title


def print_student_sentence(name, age, today):
    """
    :param name:
    :param age:
    :param today:
    :return: None
    """
    print(f"{name} is aged {age}. He is a passionate learner, and he started a JD program just {today}")
    # Write code that prints out a sentence like
    # <name> is aged <age>. He is a passionate learner, and he started a JD program just <today>


print_student_sentence("Ivan", 25, "15.08.2022")

def store_sum(number1, number2, sums):
    """
    :param number1:
    :param number2:
    :param sums:
    :return: sums
    """
    sums.append(number1 + number2)
    return sums
    # Write a code that stores the sum of number1 and number2 within sums_array


print(store_sum(5, 8, []))


def get_abbreviation(string):
    """
    :param string:
    :return: abbreviation from the string (first 3 symbols). If string is shorter than 5 chars,
    return None
    """
    if len(string) < 5:
        return None
    else:
        return string[0:3]


print(get_abbreviation("CodeAcademy"))

def get_titled_string(sentence):
    """
    :param sentence:
    :return: Return a titled version of the sentence
    """
    titled = sentence.title()
    return titled

print(get_titled_string("some randome text"))


def get_is_valid_subsequence(array, sequence):
    """
    Given two non-empty arrays of integers, finish the function by adding code that determines if
    the second array is a subsequence of the first one.

    Subsequence is not mandatory adjacent in the array, but following the same order.
    Example:
    array = [5, 1, 22, 25, 6, -1, 8, 10]
    sequence = [1, 6, -1, 10]
    result: True

    :param array:
    :param sequence:
    :return: bool
    """
    index = 0
    for num in array:
        if index == len(sequence):
            return True
        if sequence[index] == num:
            index += 1

    return index == len(sequence)


arr = [5, 1, 22, 25, 6, -1, 8, 10]
seq = [1, 6, -1, 10]
print(get_is_valid_subsequence(arr, seq))
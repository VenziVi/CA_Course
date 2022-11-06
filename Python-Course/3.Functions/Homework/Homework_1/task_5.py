# 4. Write a Python function to create and print a list where the values are square of numbers
# between 1 and 30 (both included)


def squares_list_without_range(start, end):
    while start <= end:
        yield start ** 2
        start += 1


def outer_squares_list_generator(start, end):
    return (x**2 for x in range(start, end + 1))


def square_numbers(start, end):
    """
    creates a list of square number values in a given range (both inclusive)
    print created list
    input: start range, end range
    :param start:
    :param end:
    """
    squares_list = [x**2 for x in range(start, end + 1)]   # ok, but do you have solution with generator ?
    squares_list_with_generator = (x**2 for x in range(start, end + 1))

    print("inner generator comprehension -> ", list(squares_list_with_generator))
    print("inner generator comprehension -> ", list(squares_list_with_generator))
    print("outer generator comprehension -> ", list(outer_squares_list_generator(start, end)))
    print("outer generator comprehension -> ", list(outer_squares_list_generator(start, end)))
    print("generator function -> ",list(squares_list_without_range(start, end)))
    print("generator function -> ",list(squares_list_without_range(start, end)))
    print("list comprehension -> ", squares_list)
    print("list comprehension -> ", squares_list)


square_numbers(1, 30)

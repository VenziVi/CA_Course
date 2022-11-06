from random import randrange

# 3. Write a function that would return if given int is within a certain range


def is_in_range(num):
    """
    generate random range between 1 and 150
    check if number is in generated range
    :param number:
    :return bool:
    """
    start = randrange(1, 100)
    end = randrange(start, 150)
    print(f"Range: {start} - {end}")

    return True if start <= num <= end else False


print(is_in_range(55))

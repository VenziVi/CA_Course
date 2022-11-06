import traceback


class CodeAcademyException(Exception):
    pass


# if 5 < 6:
#     raise CodeAcademyException('Raised CodeAcademyException')


try:
    5 / 0
except:
    try:
        print(5 / 0)
    except:
        print("Raised zero division error")
    print("Raised zero division error")


number = 9

try:
    assert number == 0
    number += 1
except AssertionError:
    print(f"Number is actually {number}")

def store_transactions(transaction_id, transactions):
    """
    :param transaction_id:
    :param transactions:
    :return: transactions
    """
    # Write code that stores the transaction_id if it is an even number
    # The function should return the transactions

    transactions.extend([transaction for transaction in transaction_id if transaction % 2 == 0])

    return transactions


def pretty_print_dict(dictionary, tab_count):
    """
    :param dictionary:
    :param tab_count:
    :return: NOne

    If we have the following dictionary
    {
        level1: {
            attr1: value,
            attr2: value,
            level2: {
                attr1: value,
                attr2: value,
                level3: {
                    attr1: value,
                }
            }
        }
    }
    The desired output is the dictionary data printed in a pretty manner - tabulated (4 tabs) per
    level
    """
    for key, value in dictionary.items():
        if isinstance(value, dict):
            print("\t" * tab_count + f"{key}")
            pretty_print_dict(value, tab_count + 1)
        else:
            print("\t" * tab_count + f"{key}: {value}")


def get_chars_count(string):
    """
    :param string:
    :return: dict holding string chars count
    """
    return {string: len(string)}


def get_number_sum(array, target_sum):
    """
    Example:
    array = [3, 5, -4, 8, 11, 1, -1, 6]
    target_sum = 10

    result = [-1, 11]

    :param array: Non-empty array of integers
    :param target_sum: integer
    :return: new array holding 2 numbers which sum = target_sum. If no such numbers, return []
    """
    result_array = []

    num_set = set(array)
    for num in array:
        num_set.remove(num)
        searched = target_sum - num
        if  searched in num_set:
            result_array.append(num)
            result_array.append(searched)
            return result_array
        num_set.add(num)
    '''
    array.sort()
    second_num_index = 0
    
    for num in array:
        second_num_index += 1
        searched = target_sum - num
        if searched in array[:second_num_index - 1] + array[second_num_index:]:
            result_array.append(num)
            result_array.append(searched)
            return result_array

    for num_a in array:
        second_num_index += 1
        for num_b in array[second_num_index:]:
            if (num_a + num_b) == target_sum:
                result_array.append(num_a)
                result_array.append(num_b)
                return result_array
    '''
    return result_array


def get_is_palindrome(string):
    """
    Finish the function by adding code that returns a boolean with palindrome check.
    A string is palindrome if it is written the same forward and backward. Single char string is
    a palindrome string.

    Example:
    string = 'abcdcba'
    result: True

    :param string:
    :return: bool
    """
    str_length = len(string)

    if str_length == 0:
        return False

    if str_length == 1:
        return True

    end = str_length / 2
    char_index = 0

    while char_index <= end:
        if string[char_index] != string[-abs(char_index + 1)]:
            return False
        char_index += 1

    return True


print("-----------1.store_transactions-----------------")

transactions_even = []
transactions_list = [1234, 1257, 2359, 2547, 2356, 2968]
store_transactions(transactions_list, transactions_even)
print(transactions_even)

print("-----------2.pretty_print_dict-----------------")

test = {
        "level1": {
            "attr1": 5,
            "attr2": 55,
            "level2": {
                "attr1": 44,
                "attr2": 3,
                "level3": {
                    "attr1": 2,
                }
            }
        }
    }

tab = 0

pretty_print_dict(test, tab)

print("-----------3.get_chars_count-----------------")

print(get_chars_count("random"))

print("-----------4.get_number_sum-----------------")

array = [3, 5, -4, 8, 11, 1, -1, 6]
target_sum = 10
print(get_number_sum(array, target_sum))

print("-----------5.get_is_palindrome-----------------")

print(get_is_palindrome("abcdcba"))
print(get_is_palindrome("asdbsa"))
print(get_is_palindrome("a"))

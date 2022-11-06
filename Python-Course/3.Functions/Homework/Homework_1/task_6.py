# **5. Write a function that accepts multidimensional list and prints out list elements nested by
# their dimension:
# Example: [ [1, 2, [3, 4, [6]],
#            [[], [], [3, 4, 5]] ]
# 1, 2
#      3, 4
#      6
#
#
#      3, 4, 5
#
# Hint: You may, or you may not use recursion

was_number = False
was_bracket = False


def print_number(value, indent, is_first_num):
    if is_first_num:
        print("\t" * (indent - 1) + f"{value}", end="")
    else:
        print(f", {value}", end="")


def is_new_line(indent, list_size=1):
    global was_bracket
    if not list_size or (indent and was_number and not was_bracket):
        if list_size and was_number:
            was_bracket = True
        print()


def pretty_print_md_list(md_list, indent):
    """
    input: multidimensional list, indent
    prints multidimensional list elements nested by their dimension
    using recursion
    :param md_list:
    :param indent:
    """
    is_first_num = True
    global was_number
    global was_bracket

    for value in md_list:
        if isinstance(value, list):
            is_new_line(indent, len(value))
            pretty_print_md_list(value, indent+1)
            is_new_line(indent)
            is_first_num = True
            was_number = False
        else:
            print_number(value, indent, is_first_num)
            is_first_num = False
            was_number = True
            was_bracket = False


pretty_print_md_list([[1, [[[[[]]]], 4, [3, []]], 1, 2, [3, 4, [6, [1]], 9]],
                      [1, [8, [], [6, [1, 4, 5, 6, [7]]]], [0, 5], [], [3, 4, 5]]], 0)

print('-------------------------------')

pretty_print_md_list([[1, 2, [3, 4, [6]]], [[], [], [3, 4, 5]]], 0)


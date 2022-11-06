import re


def text_match(text):
    """
        Write a Python program that matches a string that has an 'a' followed by anything, ending in 'b'
        Example:
        Input : "aabbbbd"
        Output: Not matched!
        param: text
        return: Not matched or matched
    """
    return "Matched." if re.fullmatch(r"^(\S*)[?=.*a](.?\S+)b$", text) else "Not matched!"


first_text = "sfsfafgb"
print(text_match(first_text))

new_text = ""
def text_match_second(txt):
    """
        Write a Python program to concatenate the consecutive numbers in a given string.
        Example:
        Input : "Enter at 1 20 Kearny Street. The security desk can direct you to floor 1 6.
         Please have your identification ready."
        Output: "Enter at 120 Kearny Street. The security desk can direct you to floor 16.
         Please have your identification ready."
        param: txt, new_txt
        return: new_txt
    """
    global new_text
    new_text = re.sub(r"(?<=\d)\s(?=\d)", "", txt)


second_text = "Enter at 1 20 Kearny Street. The security desk can direct you to floor 1 6. " \
              "Please have your identification ready."
text_match_second(second_text)
print(new_text)



def text_match_third(text):
    """
    Write a Python program that matches a string that has an 'a' followed by zero or more b's.
    param: text
    return: Not matched or matched
    """
    return "Matched." if re.fullmatch(r"^(\w*)ab*$", text) else "Not matched!"


third_text = "endswithabbdas"
print(text_match_third(third_text))

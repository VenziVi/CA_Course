# Write a class which have function, which will find all such numbers between 200 and 240
# (both included) such that each digit of the number is an even number.
# The numbers obtained should be printed in a csv sequence on a single line.
# Create unit test to test the function.
import csv
import os
from pathlib import Path


OUTPUT_DIR = Path(os.path.abspath(__file__)).parent


class EvenNumbers:
    def __init__(self):
        self.start = 200
        self.end = 240
        self.result = []

    def even_nums(self):
        for num in range(self.start, self.end + 1):
            if self.is_numbers_even(num):
                self.result.append(num)
        self.write_to_csv()

    @staticmethod
    def is_numbers_even(num):
        for digit in str(num):
            if int(digit) % 2 != 0:
                return False
        return True

    def write_to_csv(self):
        with open(os.path.join(OUTPUT_DIR, "even_numbers.csv"), "w") as output:
            writer = csv.writer(output)
            writer.writerow(self.result)

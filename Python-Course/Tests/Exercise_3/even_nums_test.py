import unittest
from even_nums import EvenNumbers


class EvenNumsTest(unittest.TestCase):
    def setUp(self):
        self.en = EvenNumbers()
        self.en.even_nums()

    def test_is_numbers_even(self):
        self.assertTrue(self.en.is_numbers_even(222))

    def test_is_numbers_even_with_false(self):
        self.assertFalse(self.en.is_numbers_even(232))

    def test_even_numbers_result_equal(self):
        expected = [200, 202, 204, 206, 208, 220, 222, 224, 226, 228, 240]
        actual = self.en.result
        self.assertEqual(expected, actual)

    def test_even_numbers_result_not_equal(self):
        expected = [200, 202, 204, 216, 208, 220, 232, 224, 226, 228, 240]
        actual = self.en.result
        self.assertNotEqual(expected, actual)


if __name__ == "__main__":
    unittest.main()

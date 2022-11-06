import unittest
from calc_string import CalcString


class CalcStringTest(unittest.TestCase):
    def setUp(self):
        self.str_class = CalcString()

    def test_calc_freq(self):
        expected = {'I': 5, 'and': 1, 'because': 2, 'but': 1,  'feel': 1, 'felt': 1, 'happy': 4, 'knew': 1,
                    'not': 1, 'others': 1, 'really': 1, 'saw': 1, 'should': 1, 'the': 1, 'was': 1, 'were': 1}

        self.assertEqual(expected, self.str_class.calc_freq())


if __name__ == "__main__":
    unittest.main()

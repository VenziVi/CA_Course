import unittest
from functions import power


class PowerFunctionTests(unittest.TestCase):

    def test_power_with_success(self):
        self.assertEqual(power(2, 3), 8)

    def test_power_with_incorrect_test(self):
        self.assertNotEqual(power(2, 3), 9)


class CommonTest(unittest.TestCase):
    def test_membership(self):
        set1 = set()
        set2 = set()
        set1.add(2)
        set1.add(1)
        set2.add(1)
        set2.add(2)

        self.assertIsInstance([], list)
        self.assertNotIn(2, [1, 3, 5, 4])
        self.assertIn(2, [1, 2, 3, 4])
        self.assertListEqual([1, 2, 3], [1, 2, 3])
        self.assertTupleEqual((1, 5, 6), (1, 5, 6))
        self.assertSetEqual(set1, set2)
        self.assertNotIn(4, set2)
        self.assertIn(2, (1, 2, 3, 4))
        self.assertIn("3", {"1": 2, "3": 4})

    def test_simple_operations(self):

        self.assertEqual(5 - 2, 3)
        self.assertNotEqual(10 - 4, 7)
        self.assertEqual(2 + 2, 4)
        self.assertTrue(10 % 2 == 0)
        self.assertFalse(10 % 2 == 1)
        self.assertEqual(5 // 2, 2)
        self.assertEqual("a" + "s", "as")
        self.assertEqual("4" + "5", "45")
        self.assertAlmostEqual(2.3 + 2.4, 4.7)
        self.assertNotEqual(2.3 + 2.4, 4.7)
        self.assertEqual(2 ** 3, 8)
        self.assertTrue(2)
        #self.assertRaises(ValueError, int("a"))

    def test_simple_functionality(self):
        lst = [1, 2, 3]
        self.assertEqual(lst + [4, 5], [1, 2, 3, 4, 5])
        self.assertNotEqual(lst + [4, 5], [1, 2, 6, 4, 5])
        self.assertEqual(sum(lst), 6)
        self.assertEqual(max(lst), 3)
        lst.append(4)
        self.assertEqual(lst, [1, 2, 3, 4])
        lst.pop(1)
        self.assertEqual(lst, [1, 3, 4])

        t_set = set()
        self.assertEqual(t_set, set())
        t_set.add(5)
        self.assertNotEqual(t_set, set())

        t_dict = {"1": "a"}
        self.assertEqual(t_dict, {"1": "a"})
        t_dict.update({"2": "b"})
        self.assertEqual(t_dict, {"1": "a", "2": "b"})
        temp = t_dict.pop("1")
        self.assertEqual(t_dict, {"2": "b"})
        self.assertEqual(temp, "a")





if __name__ == "__main__":
    unittest.main()
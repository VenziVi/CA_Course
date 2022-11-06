import unittest
from triangle import Triangle


class TriangleTest(unittest.TestCase):
    def setUp(self):
        self.triangle = Triangle(3, 4, 5)

    def test_perimeter_correct_result(self):
        self.assertEqual(self.triangle.calc_perimetr(), 12)

    def test_parameter_incorrect_result(self):
        self.assertNotEqual(self.triangle.calc_perimetr(), 15)

    def test_area_correct_result(self):
        self.assertEqual(self.triangle.calc_area(), 6)

    def test_area_incorrect_result(self):
        self.assertNotEqual(self.triangle.calc_area(), 9)

    def test_triangle_setter_side_a_raises_for_min(self):
        with self.assertRaises(ValueError): self.triangle.side_a = -2

    def test_triangle_setter_side_b_raises_for_min(self):
        with self.assertRaises(ValueError): self.triangle.side_b = -2

    def test_triangle_setter_side_c_raises_for_min(self):
        with self.assertRaises(ValueError): self.triangle.side_c = -2

    def test_triangle_setter_side_a_raises_for_max(self):
        with self.assertRaises(ValueError): self.triangle.side_a = 21

    def test_triangle_setter_side_b_raises_for_max(self):
        with self.assertRaises(ValueError): self.triangle.side_b = 21

    def test_triangle_setter_side_c_raises_for_max(self):
        with self.assertRaises(ValueError): self.triangle.side_c = 21

    def test_triangle_getter_side_a(self):
        self.triangle.side_a = 2
        self.assertEqual(self.triangle.side_a, 2)

    def test_triangle_getter_side_b(self):
        self.triangle.side_b = 2
        self.assertEqual(self.triangle.side_b, 2)

    def test_triangle_getter_side_c(self):
        self.triangle.side_c = 2
        self.assertEqual(self.triangle.side_c, 2)

    def test_str_method(self):
        self.assertEqual(self.triangle.__str__(), "parameter: 12, area: 6.0")

if __name__ == "__main__":
    unittest.main()

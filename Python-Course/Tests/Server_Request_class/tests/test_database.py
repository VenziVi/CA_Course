import hashlib
import unittest
from Tests.Server_Request_class.server_request import Database


class DatabaseTest(unittest.TestCase):
    def setUp(self):
        self.db = Database()
        self.db.register_user("Ivan", "5.5.5.5")
        pass

    def test_register_user_success(self):
        self.assertEqual("Database has 1 users", self.db.__str__())

    def test_register_existing_user(self):
        actual = self.db.register_user("Ivan", "5.5.5.5")
        expected = self.db.get_user_data("Ivan", "5.5.5.5")
        self.assertEqual(actual, expected)

    def test_get_user_data_with_empty_db(self):
        expected = "Unknown user Mitko, ip 1.1.1.1. Request denied!"
        actual = self.db.get_user_data("Mitko", "1.1.1.1")
        self.assertEqual(expected, actual)

    def test_get_user_with_existing(self):
        expected = hashlib.sha256("1".encode()).hexdigest()
        actual = self.db.get_user_data("Ivan", "5.5.5.5")
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
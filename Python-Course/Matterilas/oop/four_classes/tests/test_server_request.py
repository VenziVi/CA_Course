import hashlib
import unittest
from oop.four_classes.server_request import Database, Request, Server


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


class RequestTests(unittest.TestCase):
    def setUp(self):
        self.test_request = Request("user", "4.4.4.4")
        pass

    def test_request_instance(self):
        expected = "Request data - name: user, IP: 4.4.4.4"
        result = self.test_request.__str__()
        self.assertEqual(expected, result)

    def test_request_instance_wrong_data(self):
        expected = "Request data - name: user, IP: 4.5.4.4"
        result = self.test_request.__str__()
        self.assertNotEqual(expected, result)

    def test_request_instance_rises_error(self):
        self.assertRaises(TypeError, Request("user", [44]))


class ServerTests(unittest.TestCase):
    def setUp(self):
        self.server = Server(8, 1)
        self.server.db.register_user("Ivan", "4.4.4.4")
        self.req = Request("Ivan", "4.4.4.4")
        self.req2 = Request("Petar", "5.5.5.5")

    def test_process_request_power_off_ex(self):
        with self.assertRaises(Exception):
            self.server.process_request(self.req)

    def test_process_request_not_instance_ex(self):
        self.server.power_on()
        with self.assertRaises(Exception):
            self.server.process_request([1, 3, 5])

    def test_process_request_success(self):
        self.server.power_on()
        self.server.process_request(self.req)
        self.assertTrue(self.req.is_authenticated)

    def test_process_request_not_success(self):
        self.server.power_on()
        self.server.process_request(self.req2)
        self.assertFalse(self.req.is_authenticated)

    def test_server_power_off(self):
        self.assertFalse(self.server.is_on)

    def test_server_power_on(self):
        self.server.power_on()
        self.assertTrue(self.server.is_on)

    def test_server_str(self):
        expected = "Server info - Ram: 8GB, storage: 1TB"
        actual = self.server.__str__()
        self.assertEqual(actual, expected)

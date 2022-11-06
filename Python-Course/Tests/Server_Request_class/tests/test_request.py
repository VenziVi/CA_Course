
import unittest
from Tests.Server_Request_class.server_request import Request


class RequestTests(unittest.TestCase):
    def setUp(self) -> None:
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


if __name__ == "__main__":
    unittest.main()
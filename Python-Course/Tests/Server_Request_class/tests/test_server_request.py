import hashlib
import unittest
from Tests.Server_Request_class.server_request import Database, Request, Server


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
        self.assertRaises(Exception, self.server.process_request, [1, 3, 4])


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


if __name__ == "__main__":
    unittest.main()
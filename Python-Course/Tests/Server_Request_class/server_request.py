import hashlib


class Database:
    _instance = None
    _users = {}

    def __new__(cls, *args, **kwargs):
        if cls._instance is not None:
            return cls._instance
        _instance = super().__new__(cls)
        return _instance

    @staticmethod
    def __encrypt_user_id(user_id):
        return hashlib.sha256(f"{user_id}".encode()).hexdigest()

    def register_user(self, user_name, ip):
        if user := self.__get_user(user_name, ip):
            print("User already exists.")
            return user

        self._users[(user_name, ip)] = self.__encrypt_user_id(len(self._users) + 1)
        print("User saved")

    def __get_user(self, user_name, ip):
        return self._users.get((user_name, ip))

    def get_user_data(self, user_name, ip):
        if user := self.__get_user(user_name, ip):
            print(user_name, ip, "->", user)
            return user
        else:
            return f"Unknown user {user_name}, ip {ip}. Request denied!"

    def __str__(self):
        return f"Database has {len(self._users)} users"


class Request:
    def __init__(self, user: str, ip: str):
        self.user = self.__validate_data(user)
        self.ip = self.__validate_data(ip)
        self.is_authenticated = False

    def __validate_data(self, data):
        if not isinstance(data, str):
            try:
                return str(data)
            except TypeError:
                print(f"Invalid data {data}, type: {type(data)}")
        return data

    def __str__(self):
        return f"Request data - name: {self.user}, IP: {self.ip}"


class Server:
    def __init__(self, ram: int, storage: int):
        self.db = Database()
        self.ram = ram
        self.storage = storage
        self.is_on = False

    def power_on(self):
        self.is_on = True

    def power_off(self):
        self.is_on = False

    def process_request(self, request: Request):
        if not self.is_on:
            raise Exception("Server is off!")

        if not isinstance(request, Request):
            raise Exception("Invalid request!")

        if self.db.get_user_data(request.user, request.ip):
            request.is_authenticated = True

    def __str__(self):
        return f"Server info - Ram: {self.ram}GB, storage: {self.storage}TB"


# server = Server(256, 100)
# req1 = Request("Vasko", "211.185.1.15")
# req2 = Request("Misho", "222.103.33.144")
# server.power_on()
# server.db.register_user("Vasko", "211.185.1.15")
# server.process_request(req1)
# server.process_request(req2)
# server.power_off()
#
# server2 = Server(128, 50)
# print(server2.db)
# print(server2.db._users)

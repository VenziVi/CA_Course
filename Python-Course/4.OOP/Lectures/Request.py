class User:

    def __init__(self, user_name, password):
        self.user_name = user_name
        self.password = password

    def __str__(self):
        return f"{self.user_name}"


class Request:

    def __init__(self, ip, user):
        self.ip = ip
        self.user = user
        self.is_authenticated = False

    def __str__(self):
        return f"User: {self.user}, authenticated = {self.is_authenticated}"

    def authenticate_user(self):
        self.is_authenticated = True


class Server:

    def __init__(self, db):
        self.db = db
        self.__is_on = False

    def power_on(self):
        if not self.__is_on:
            self.__is_on = True
            print("Server is turned on.")
        else:
            print("Server is already turned on.")

    def power_off(self):
        if self.__is_on:
            self.__is_on = False
            print("Server is turned off.")
        else:
            print("Server is already turned off.")

    def authenticate_user(self, request):
        if self.db.get(request.user.user_name) and \
           self.db[request.user.user_name] == request.user.password:
            request.authenticate_user()
            return True
        return False

    def process_request(self, request):
        self.authenticate_user(request)
        if request.is_authenticated:
            return "200"
        else:
            print(f"User {request.user} is not authenticated!")
            return "418"


users_data = {"Ivan": "123", "Alex": "456"}
user_1 = User("Ivan", "123")
user_2 = User("Petar", "456")
server = Server(users_data)
request_1 = Request("77.85.89.157", user_1)
request_2 = Request("77.85.89.157", user_2)

print(request_1)
print(request_2)

print(server.process_request(request_1))
print(server.process_request(request_2))

print(request_1)
print(request_2)



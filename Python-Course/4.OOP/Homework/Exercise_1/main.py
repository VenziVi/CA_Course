import time
from competitor_class import Competitor

RESULT_HEADER = "| reg.num |   first name    |    last name    |  starting  | finishing  |   result   |" \
                "\n--------------------------------------------------------------------------------------"
test_list = ["1, Ivan, Ivanov", "2, Aleksandar, Petrov", "3, Petar, Nikolov", "4, Alksandar, Stoqnov"]

def add_competitor(data: str, competitors: dict):
    """
    try to create Competitor class instance with input values
    on success, add competitor to competitors collection
    with key: registration number and value: Competitor
    else print the raised exception message
    input data format: "registration number, first name, last name"
    :param data:
    :param competitors:
    """
    number, first_name, last_name = data.split(", ")
    competitor_number = int(number)
    if competitors.get(competitor_number):
        print(f"Competitor with number: {number} already exists!")
    else:
        try:
            new_competitor = Competitor.create_competitor(competitor_number, first_name, last_name)
        except ValueError as ve:
            print(ve)
        except:
            print("Unexpected error! Call support!")
        else:
            competitors[new_competitor.registration_number] = new_competitor


def set_test_competitors(competitors):
    """
    sets competitors collection with test data
    from test_list
    :param competitors:
    """
    for competitor in test_list:
        add_competitor(competitor, competitors)


def start_competition(competitors: dict):
    """
    sets competitors start time by releasing them every 5 seconds
    :param competitors:
    """
    print("Competitors:", ", ".join([str(i) for i in competitors.keys()]))
    print("Ready, set, go...")
    for competitor in competitors.values():
        competitor.set_starting_time()
        time.sleep(5)


def competitor_finish(num: str, competitors: dict, finished_competitors: list):
    """
    check if the competitor's registration number contains in the competitor dict
    and if he exists in the finished competitors list
    set competitor's finish time and result time
    add a competitor to the finished competitors list
    :param num:
    :param competitors:
    :param finished_competitors:
    """
    competitor = competitors.get(int(num))
    if competitor and competitor not in finished_competitors:
        competitor.set_finish_time()
        competitor.calculate_result_time()
        finished_competitors.append(competitor)
        print(f"Competitor with number: {num} finished.")
    else:
        print("Invalid competitor number!")


def set_competitors(competitors: dict):
    """
    enter competitor information in format "registration number, first name, last name"
    adds a competitor to the competitors collection
    until "exit" command is entered
    :param competitors:
    """
    while True:
        data = input("Enter competitor info(number, first name, last name): ")
        if data == "exit":
            break
        add_competitor(data, competitors)


def set_competitors_finish_time(competitors: dict, finished_competitors: list):
    """
    waiting for competitor's registration number to be entered when he crosses the finish line
    and calls competitor_finish function with current number
    while all the competitors cross the finish line
    :param competitors:
    :param finished_competitors:
    """
    while len(finished_competitors) < len(competitors):
        num = input("Enter finished competitor number: ")
        competitor_finish(num, competitors, finished_competitors)


def print_competition_results(competitors: list):
    """
    print competitor information in order of crossing the finish line
    in a table format
    :param competitors:
    """
    print(RESULT_HEADER)
    for competitor in competitors:
        print(competitor)


def competition():
    competitors = {}
    finished_competitors = []
    #set_competitors(competitors)
    set_test_competitors(competitors)
    start_competition(competitors)
    set_competitors_finish_time(competitors, finished_competitors)
    print_competition_results(finished_competitors)


if __name__ == "__main__":
    competition()

"""
In order to complete the request's handler you'll need to install requirements.txt which
now holds the requests library reference.

You'll need to finish the RequestsHandler class which purpose is to request data from an open
API which currently has two endpoints:

<base_url>:/oop/api/orders/files
Allowed methods - GET
Returns: [filenames]

<base_url>:/oop/api/orders/file
Allowed methods - GET
Params: You need to supply a filename as a JSON data:
{"file": some_file_name}
Returns: File data, paginated. Note that you may need to perform more than one request in order
to get the whole File data!

Tips:
- Perform requests and inspect response that the API returns.
- Think about the pagination data
"""
from urllib.parse import urljoin

import requests
from bs4 import BeautifulSoup


class UnsuccessfulNewsRequest(ConnectionError):
    def __init__(self, base_url, url):
        super().__init__("UnsuccessfulNewsRequest error")
        self.base_url = base_url
        self.url = url

    def get_not_responding_url(self):
        return (
            f"Base url ({self.base_url}) (server) seems to be inactive"
            f" when trying to reach {self.url}"
        )


class RequestsHandler:
    BASE_URL = f"http://127.0.0.1:7300"
    FILES_URL = "oop/api/orders/files"
    FILE_URL = "oop/api/orders/file"

    def get_files(self):
        response = requests.get(urljoin(self.BASE_URL, self.FILES_URL), timeout=3)
        response.raise_for_status()
        return response.json()

    def get_file(self, filename):
        json = {
            "file": filename,
        }

        response = requests.get(urljoin(self.BASE_URL, self.FILE_URL), json=json, timeout=3)
        response.raise_for_status()

        result = []
        data_json = response.json()
        result.extend(data_json['results'])

        while data_json['next']:
            response = requests.get(urljoin(self.BASE_URL, data_json['next']), json=json, timeout=3)
            data_json = response.json()
            result.extend(data_json['results'])

        return result

import unittest
from unittest.mock import patch

import requests

from oop.workshop.requests_handler import RequestsHandler
from oop.workshop.tests.mocked_data import mocked_html_text


def mock_response(*args, **kwargs):
    class MockResponse:
        def __init__(self, *args, **kwargs):
            self.json = lambda: kwargs.pop("json")
            self.status_code = kwargs.pop("status_code", 200)
            self.raise_for_status = lambda: True
    return MockResponse(*args, **kwargs)


def mock_response_text(*args, **kwargs):
    class MockResponse:
        def __init__(self, *args, **kwargs):
            self.status_code = 200
            self.raise_for_status = lambda: True
            self.text = kwargs.pop("html_text")
    return MockResponse(*args, **kwargs)


class RequestsHandlerTests(unittest.TestCase):
    def setUp(self) -> None:
        super().setUp()

        self.requests_handler = RequestsHandler()

    @patch("requests.get", side_effect=lambda *args, **kwargs: mock_response(*args, json=["file1.json", "file2.json"]))
    def test_get_files(self, mock_get):
        """ Test files list is successfully received. """
        files = self.requests_handler.get_files()
        self.assertEqual(files, ["file1.json", "file2.json"])
        mock_get.assert_called()

    @patch("requests.post", side_effect=lambda *args, **kwargs: mock_response(json={"success":True}, status_code=204))
    def test_simple_post(self, mock_post):
        res = self.requests_handler.simple_post()
        self.assertEqual(res.status_code, 204)
        self.assertTrue(res.json()["success"])
        mock_post.assert_called()

    @patch("requests.get", side_effect=lambda *args, **kwargs:mock_response(*args, json={"results": {"name": "pesho"}, "next": None}))
    def test_get_file(self, mock_get):
        """ Test files list is successfully received. """
        response_json = self.requests_handler.get_file("some-file")
        self.assertEqual(response_json["name"], "pesho")
        mock_get.assert_called()

    @patch("requests.get", side_effect=lambda *args, **kwargs: mock_response_text(html_text=mocked_html_text))
    def test_get_news(self, mock_get):
        """ Test news content is get. """

        factor_rates = self.requests_handler.get_news_content("/wolf-news")
        mock_get.assert_called()
        print(factor_rates)

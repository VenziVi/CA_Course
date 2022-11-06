import json
from requests_handler import RequestsHandler
from export_builder import OrdersDataExportBuilder

"""
1. Data would come from a running web-server on your side - CodeAcademyDjango
2. Data should be collected
3. Data should be passed to a Exporter
4. Based on desired export Exporter should create it and store it on your Filesystem.
5. Data could be exported in a grouped way.
"""


def manage_data(file_format, group_by):
    result_list = []
    request = RequestsHandler()
    files = request.get_files()

    for file in files:
        result_list.extend(request.get_file(file))

    data_builder = OrdersDataExportBuilder(result_list)
    data_builder.export_grouped_by(file_format, group_by)


if __name__ == "__main__":
    manage_data('csv', 'location')

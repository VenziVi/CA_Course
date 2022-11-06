import json

from oop.workshop.export_builder import OrdersDataExportBuilder
from oop.workshop.requests_handler import RequestsHandler

rq = RequestsHandler()
# files = rq.get_files()
# file_data = rq.get_file(files[0])
# file_timespan = files[0].split("timespan_")[0][0]
# export_builder = OrdersDataExportBuilder(file_data, file_timespan)
# export_builder.export_grouped_by(export_format="xml")

news_factors = rq.get_news_factors()
print(json.dumps(news_factors, indent=4))

"""
1. Data would come from a running web-server on your side - CodeAcademyDjango
2. Data should be collected
3. Data should be passed to a Exporter
4. Based on desired export Exporter should create it and store it on your Filesystem.
5. Data could be exported in a grouped way.
"""

Database = object()

def custom_function_one():
    Database.connect()
    return True

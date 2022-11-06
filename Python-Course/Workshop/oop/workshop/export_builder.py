import csv
import itertools
import os
import xml.etree.ElementTree as eT
from settings.testing import OUTPUT_DIR

CSV_HEADER = ['OrderId', 'location', 'to_location', 'product', 'quantity']
LOCATION_INDEX = 1
PRODUCT_INDEX = 3


class OrdersDataExportBuilder:
    ALLOWED_GROUPERS = {"location", "product"}

    def __init__(self, data):
        self.fetched_data = data
        self.timespan = None

    @staticmethod
    def set_sort_index(group_by):
        return LOCATION_INDEX if group_by == 'location' else PRODUCT_INDEX

    def __extract_data(self):
        new_list = []
        for order in self.fetched_data:
            for items in order['details']:
                new_list.append(
                    [order['order_id'], items['location'], items['tolocation'], items['product'], items['qty']])
        return new_list

    def __export_as_csv(self, group_by):
        result_list = self.__extract_data()
        result_list = sorted(result_list, key=lambda x: x[self.set_sort_index(group_by)])

        with open(
            os.path.join(
                OUTPUT_DIR,
                f"{group_by}_grouped_orders_data_timespan_{self.timespan}.csv",
            ),
            "w", newline=''
        ) as output:
            writer = csv.writer(output)
            writer.writerow(CSV_HEADER)
            writer.writerows(result_list)

    def __export_as_xml(self, group_by):
        document = eT.Element("OrdersData")

    def export_grouped_by(self, _format, group_by):
        if group_by not in self.ALLOWED_GROUPERS:
            raise ValueError(f"Unknown grouping element: {group_by}")

        if _format == "csv":
            self.__export_as_csv(group_by)
        elif _format == "xml":
            self.__export_as_xml(group_by)
        else:
            raise ValueError(f"Unknown format: {_format}")

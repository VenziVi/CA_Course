import csv
import itertools
import os
import xml.etree.ElementTree as eT

from settings.testing import OUTPUT_DIR


class OrdersDataExportBuilder:
    ALLOWED_GROUPERS = {"location", "product"}

    def __init__(self, data, timespan):
        self.fetched_data = data
        self.timespan = timespan

    def __export_as_csv(self, group_by):
        with open(
            os.path.join(
                OUTPUT_DIR,
                f"{group_by}_grouped_orders_data_timespan_{self.timespan}.csv",
            ),
            "w",
        ) as output:
            writer = csv.writer(output)
            writer.writerow(["Orders count", len(self.fetched_data)])
            writer.writerow([])

            for order_data in self.fetched_data:
                writer.writerow([order_data["order_id"]])
                for grouper, grouped_data in itertools.groupby(
                    order_data["details"],
                    key=lambda item: item[group_by],
                ):
                    writer.writerow(["", grouper])
                    writer.writerow(["", "", "product", "qty", "tolocation"])
                    for product in grouped_data:
                        writer.writerow(
                            [
                                "",
                                "",
                                product["product"],
                                product["qty"],
                                product["tolocation"],
                            ],
                        )

    def __export_as_xml(self, group_by):
        document = eT.Element("OrdersData")
        eT.SubElement(document, "OrdersCount").text = str(len(self.fetched_data))
        orders = eT.SubElement(document, "Orders")
        for order_data in self.fetched_data:
            for grouper, grouped_data in itertools.groupby(
                order_data["details"],
                key=lambda item: item[group_by],
            ):
                order = eT.SubElement(orders, "Order")
                eT.SubElement(order, "id").text = str(order_data["order_id"])
                locations = eT.SubElement(order, "Locations")
                location = eT.SubElement(locations, "location")
                location.text = grouper
                products = eT.SubElement(location, "products")
                for product in grouped_data:
                    p = eT.SubElement(products, "product")
                    eT.SubElement(p, "product_code").text = product["product"]
                    eT.SubElement(p, "qty").text = str(product["qty"])
                    eT.SubElement(p, "tolocation").text = product["tolocation"]
        tree = eT.ElementTree(document)
        return tree.write(
            os.path.join(OUTPUT_DIR, f"export_orders_timespan_{self.timespan}.xml")
        )

    def export_grouped_by(self, export_format="csv", group_by="location"):
        if group_by not in self.ALLOWED_GROUPERS:
            raise ValueError(f"Unknown grouping element: {group_by}")

        if export_format == "csv":
            self.__export_as_csv(group_by)
        elif export_format == "xml":
            self.__export_as_xml(group_by)
        else:
            raise ValueError(f"Unknown format: {export_format}")

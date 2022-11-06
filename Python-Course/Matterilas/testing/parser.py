from argparse import ArgumentParser


def main():
    parser = ArgumentParser()
    parser.add_argument("-number-of-recipes", type=int, help="store number of recipes")
    parser.add_argument("--products", type=str, help="store products")
    parser.add_argument("--dish", type=str, help="store dish")
    parser.add_argument(
        "--last-cooked",
        help="last cooked",
        action="store_true",
    )
    args = parser.parse_args()
    print(args)

    """
    scraper = ScraperClass(args)
    collector = Collector(scraper.data)
    collector.collect_data()
    
    sender = SenderData(collector.data)
    sender.send_to_gsheets()
    """


if __name__ == "__main__":
    main()

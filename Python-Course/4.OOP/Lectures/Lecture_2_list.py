class OddsOnly(list):
    def append(self, item: int) -> None:
        if item % 2 != 0:
            super().append(item)
            return
        raise
        # raise ValueError("Only odd ints are acceptable")


class EvensOnly(list):
    def append(self, item: int) -> None:
        if item % 2 == 0:
            super().append(item)
            return
        raise ValueError("Only even ints are acceptable")


# evens_only = EvensOnly()
# while len(evens_only) < 100:
#     random_integer = random.randint(1, 100)
#     try:
#         evens_only.append(random_integer)
#     except ValueError:
#         continue

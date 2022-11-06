class DictOfShortKeys(dict):
    MAX_KEY_LENGTH = 6

    def __setitem__(self, key, value):
        if not isinstance(key, str):
            raise ValueError("Only string keys are accepted")
        if len(key) > self.MAX_KEY_LENGTH:
            raise ValueError(
                f"Key length is over key length limit: {len(key)} > {self.MAX_KEY_LENGTH}",
            )
        super().__setitem__(key, value)



d1 = DictOfShortKeys()
d1["this is to long name"] = "Ivan"

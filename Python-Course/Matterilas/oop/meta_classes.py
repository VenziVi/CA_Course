# class Base:
#     def foo(self):
#         raise NotImplementedError()
#
#     def bar(self):
#         raise NotImplementedError()
#
#
# class Concrete(Base):
#     def foo(self):
#         return "foo() called"
#
#     # Oh no, we forgot to override bar()...
#     # def bar(self):
#     #     return "bar() called"
#
#
# c = Concrete()
# print(c.foo())
# c.bar()


from abc import ABCMeta, abstractmethod


class Base(metaclass=ABCMeta):
    @abstractmethod
    def foo(self):
        pass

    @abstractmethod
    def bar(self):
        pass


class Concrete(Base):
    def foo(self):
        print(f"Coming from concrete {self.__class__} foo")

    def bar(self):
        print(f"Coming from concrete {self.__class__} bar")

    # We forgot to declare bar() again...


assert issubclass(Concrete, Base)


class Exact(Base):
    def foo(self):
        print(f"Coming from exact {self.__class__} foo")

    def bar(self):
        print(f"Coming from exact {self.__class__} bar")

    # We forgot to declare bar() again...


# c = Concrete()
# e = Exact()
#
# c.foo()
# e.foo()
#
# c.bar()
# e.bar()


class AudioFile:
    def __init__(self, filename):
        if not filename.endswith(self.ext):
            raise Exception("Invalid file format")
        self.filename = filename

    def play(self):
        raise NotImplementedError("Must implement")


class MP3File(AudioFile):
    ext = "mp3"

    def play(self):
        print(f"playing {self.filename} as {self.ext}")


class OggFile(AudioFile):
    ext = "ogg"

    def play(self):
        print(f"playing {self.filename} as {self.ext}")


class WAVFile(AudioFile):
    ext = "wav"

    def play(self):
        pass


mp3 = MP3File("Titanic food.mp3")
ogg = OggFile("Unforgiven.ogg")

mp3.play()
ogg.play()

bad_mp3 = MP3File("Unforgiven.mp3")
bad_mp3.play()

wav = WAVFile("test.wav")
wav.play()


__test_var = 16


def __test_private_method():
    return "is_private"

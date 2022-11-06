class AudioFile:

    def __init__(self, file_name):
        if not file_name.endswith(self.ext):
            raise Exception("Invalid file format!")
        self.file_name = file_name

    def play(self):
        raise NotImplementedError("Must implement")


class MP3FILE(AudioFile):
    ext = "mp3"

    def play(self):
        print(f"playing {self.file_name} as {self.ext}")


class OggILE(AudioFile):
    ext = "ogg"

    def play(self):
        print(f"playing {self.file_name} as {self.ext}")


mp3 = MP3FILE("Ветрове.mp3")
ogg = OggILE("Бургаски вечери.ogg")

mp3.play()
ogg.play()


class Employee:
    pass


john = Employee()
john.name = "Doe"
john.age = 23
john.salary = 1592

print(john.name)

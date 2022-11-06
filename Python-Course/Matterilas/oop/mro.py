class A:
    def method(self):
        print("A.method() called")


class B:
    def method(self):
        print("B.method() called")


class C(A, B):
    pass


class D(B, C):
    pass


d = D()
d.method()
print(D.mro())


# What happens when inheriting from C, B vs B, C

from mystring import MyString


def test_plus_op():
    s1 = MyString("Hello")
    s2 = MyString("World")
    res = s1 + " " + s2
    assert res.c_str() == "Hello World"

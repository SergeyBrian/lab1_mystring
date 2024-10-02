from mystring import MyString


def test_plus_assign():
    s = MyString("Hello")
    s += " World"
    assert s.c_str() == "Hello World"

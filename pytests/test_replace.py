from mystring import MyString


def test_replace_from_start():
    s = MyString("LongString")
    s.replace(0, 4, "Short")
    assert s.c_str() == "ShortString"


def test_replace_from_end():
    s = MyString("LongString")
    s.replace(4, 6, "Int")
    assert s.c_str() == "LongInt"

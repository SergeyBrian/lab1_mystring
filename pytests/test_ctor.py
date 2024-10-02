from mystring import MyString


def test_constructor_default():
    s = MyString()
    assert s.length() == 0
    assert s.capacity() >= 1


def test_str_constructor():
    s = MyString("0123456789")
    assert s.length() == 10
    assert s.capacity() >= 11
    assert s.data() == "0123456789"


def test_str_with_count_constructor():
    s = MyString("0123456789", 5)
    assert s.length() == 5
    assert s.capacity() >= 6
    assert s.data() == "01234"

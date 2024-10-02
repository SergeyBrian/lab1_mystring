from mystring import MyString

s = MyString("Hello, world! Hello, world!")


def test_find_str():
    pos = s.find("Hello")
    assert pos == 0


def test_find_str_by_index():
    pos = s.find("world", 9)
    assert pos == 21


def test_find_out_of_bound():
    try:
        pos = s.find("world", 35)
    except Exception as e:
        assert str(e) == "out_of_range"
        return
    assert 0, "Should have thrown an exception"

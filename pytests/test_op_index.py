from mystring import MyString

s = MyString("Hello, world!")


def test_get_first_element():
    assert s[0] == "H"


def test_get_middle_element():
    assert s[7] == "w"


def test_get_last_element():
    assert s[s.size() - 1] == "!"


def test_get_out_of_bound():
    try:
        c = s[100]
    except Exception as e:
        assert str(e) == "out_of_range"
        return
    assert 0, "Should have thrown an exception"


def test_write_by_index():
    s[0] = "h"
    assert s[0] == "h"


def test_write_out_of_bound_by_index():
    try:
        s[100] = "h"
    except Exception as e:
        assert str(e) == "out_of_range"
        return
    assert 0, "Should have thrown an exception"

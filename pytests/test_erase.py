from mystring import MyString


def test_erase_from_start():
    s = MyString("LongString")
    s.erase(0, 4)
    assert s.length() == 6
    assert s.data() == "String"


def test_erase_from_end():
    s = MyString("LongString")
    s.erase(4, 6)
    assert s.length() == 4
    assert s.data() == "Long"


def test_erase_out_of_bound():
    s = MyString("LongString")
    try:
        s.erase(12, 6)
    except Exception as e:
        assert str(e) == "out_of_range"
        return
    assert 0, "Should have thrown an exception"

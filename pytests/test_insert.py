from mystring import MyString


def test_insert_in_empty():
    s = MyString()
    s.insert(0, "Hello")
    assert s.c_str() == "Hello"


def test_insert_in_begin():
    s = MyString(" World")
    s.insert(0, "Hello")
    assert s.c_str() == "Hello World"


def test_insert_in_middle():
    s = MyString("Hello World")
    s.insert(6, "Beautiful ", 10)
    assert s.c_str(), "Hello Beautiful World"


def test_insert_in_end():
    s = MyString("Hello")
    s.insert(5, " World")
    assert s.c_str() == "Hello World"


def test_insert_empty():
    s = MyString("Hello World")
    s.insert(6, "")
    assert s.c_str() == "Hello World"


def test_insert_empty_in_empty():
    s = MyString()
    s.insert(0, "")
    assert s.c_str() == ""
    assert s.length() == 0
    assert s.capacity() >= 1


def test_insert_into_itself():
    s = MyString("Hello")
    s.insert(5, s.c_str())
    assert s.c_str() == "HelloHello"


def test_insert_out_of_bound():
    s = MyString("Hello")

    try:
        s.insert(10, " World")
    except Exception as e:
        assert str(e) == "out_of_range"
        return
    assert 0, "Should have thrown an exception"

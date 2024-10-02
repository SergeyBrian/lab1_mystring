from mystring import MyString

string = "1234567890"
s = MyString(string)


def test_c_str():
    assert s.c_str() == string


def test_get_data():
    assert s.data() == string


def test_get_length():
    assert s.length() == 10


def test_get_size():
    assert s.size() == 10


def test_get_capacity():
    assert s.capacity() == 11


def test_get_empty():
    assert s.empty() == False


def test_get_empty_real_empty():
    s1 = MyString()
    assert s1.empty() == True

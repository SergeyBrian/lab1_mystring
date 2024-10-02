from mystring import MyString


def test_append_str():
    s2 = MyString("str2")
    s2.append("str1")
    assert s2.data() == "str2str1"

from mystring import MyString

s = MyString("Str1 Str2 Str3")


def test_substring_full():
    ssub = s.substr(5)
    assert ssub.length() == 9
    assert ssub.c_str() == "Str2 Str3"


def test_substr_len():
    ssub = s.substr(5, 4)
    assert ssub.c_str() == "Str2"

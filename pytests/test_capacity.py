from mystring import MyString

def test_shrink_to_fit():
    str1 = MyString("a" * 1000)
    str1.erase(10, 990)
    assert str1.capacity() == 1001

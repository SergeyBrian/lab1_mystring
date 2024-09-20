#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstring>
#include <string>

#include "MyStringException.h"

class MyString {
public:
    MyString();
    MyString(const char *str);
    MyString(const char *str, size_t n);
    MyString(size_t n, char c);
    MyString(const MyString& s);
    explicit MyString(const std::string& str);
    MyString(MyString&& s);
    ~MyString();

    const char *data() const;
    const char *c_str() const;
    size_t size() const;
    size_t length() const;
    bool empty() const;
    size_t capacity() const;

    void insert(size_t pos, size_t count, char c);
    void insert(size_t pos, const char *c, size_t n);
    void insert(size_t pos, const char *c);
    void insert(size_t pos, const std::string& str, size_t n);
    void insert(size_t pos, const std::string& str);

    void shrink_to_fit();

    MyString &operator=(MyString &s);
private:
    char *m_data_;
    size_t m_capacity_;
    size_t m_size_;

    void add_space(size_t pos, size_t s);
};

#endif
#include "MyString.h"

MyString::MyString() {
    m_capacity_ = 1;
    m_size_ = 0;
    m_data_ = new char[1];
    m_data_[0] = 0;
}

MyString::MyString(const char *str) : MyString(str, std::strlen(str)) {}

MyString::MyString(const char *str, size_t n) {
    m_size_ = n;
    m_capacity_ = m_size_ + 1;
    m_data_ = new char[m_capacity_];
    std::memset(m_data_, 0, m_capacity_);
    std::strncpy(m_data_, str, m_size_);
}

MyString::MyString(size_t n, char c) {
    m_size_ = n;
    m_capacity_ = m_size_ + 1;
    m_data_ = new char[m_capacity_];
    std::memset(m_data_, c, m_size_);
    m_data_[n] = 0;
}

MyString::MyString(const MyString &s) : MyString(s.c_str()) {}

MyString::MyString(const std::string& str) : MyString(str.c_str()) {}

MyString::~MyString() {
    delete[] m_data_;
}

const char *MyString::data() const {
    return m_data_;
}

const char *MyString::c_str() const {
    return m_data_;
}

size_t MyString::size() const {
    return m_size_;
}

size_t MyString::length() const {
    return m_size_;
}

bool MyString::empty() const {
    return m_size_ == 0;
}

size_t MyString::capacity() const {
    return m_capacity_;
}

// Расширяет строку, добавляя пустое пространство размера n, начинающееся с позиции pos
void MyString::add_space(size_t pos, size_t n) {
    if (pos > m_size_) {
        throw MyStringOutOfRangeException();
    }

    size_t new_size = size() + n;

    char *tmp_mem = m_data_;
    if (new_size >= m_capacity_) {
        m_capacity_ = new_size + 1;
        tmp_mem = new char[m_capacity_];
    }

    std::memcpy(tmp_mem, m_data_, pos);
    std::memcpy(tmp_mem + pos + n, m_data_ + pos, size() - pos);

    m_size_ = new_size;

    if (tmp_mem != m_data_) {
        delete[] m_data_;
        m_data_ = tmp_mem;
    }
}

void MyString::insert(size_t pos, size_t count, char c) {
    add_space(pos, count);
    std::memset(m_data_ + pos, c, count);
}

void MyString::insert(size_t pos, const char *c, size_t n) {
    char *tmp_buf = new char[n];
    std::memcpy(tmp_buf, c, n);
    add_space(pos, n);
    std::memcpy(m_data_ + pos, tmp_buf, n);
    delete[] tmp_buf;
}

void MyString::insert(size_t pos, const char *c) {
    insert(pos, c, std::strlen(c));
}

void MyString::insert(size_t pos, const std::string& str, size_t n) {
    insert(pos, str.c_str(), n);
}

void MyString::insert(size_t pos, const std::string& str) {
    insert(pos, str.c_str());
}


#include "MyString.h"
#include <iostream>

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

MyString::MyString(const std::string &str) : MyString(str.c_str()) {}

MyString::MyString(MyString &&s) {
    m_data_ = new char[s.capacity()];
    memcpy(m_data_, s.data(), s.capacity());
    m_size_ = s.size();
    m_capacity_ = s.capacity();
}

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
    std::memcpy(tmp_mem + pos + n, m_data_ + pos, size() + 1 - pos);

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

void MyString::insert(size_t pos, const std::string &str, size_t n) {
    insert(pos, str.c_str(), n);
}

void MyString::insert(size_t pos, const std::string &str) {
    insert(pos, str.c_str());
}

void MyString::shrink_to_fit() {
    if (m_size_ + 1 == m_capacity_) return;
    m_capacity_ = m_size_ + 1;
    char *tmp_mem = new char[m_capacity_];
    std::memcpy(tmp_mem, m_data_, m_capacity_);
    delete[] m_data_;
    m_data_ = tmp_mem;
}


void MyString::assign(const char *s, size_t n) {
    char *tmp_mem = m_data_;
    if (m_capacity_ <= n) {
        tmp_mem = new char[n + 1];
        m_capacity_ = n + 1;
    }

    std::memcpy(tmp_mem, s, n + 1);

    m_size_ = n;

    tmp_mem[n] = 0;

    if (tmp_mem != m_data_) {
        delete[] m_data_;
        m_data_ = tmp_mem;
    }
}

MyString &MyString::operator=(const MyString &s) {
    assign(s.data(), s.size());

    return *this;
}

MyString &MyString::operator=(const char *s) {
    assign(s, strlen(s));

    return *this;
}

MyString &MyString::operator=(const std::string &s) {
    assign(s.data(), s.size());

    return *this;
}

MyString &MyString::operator=(char c) {
    assign(&c, 1);

    return *this;
}


void MyString::erase(size_t pos, size_t count) {
    if (pos > size()) throw MyStringOutOfRangeException();
    if (count + pos > size()) count = size() - pos;
    std::memcpy(m_data_ + pos, m_data_ + pos + count, size() + 1 - pos - count);
    m_size_ -= count;
}

void MyString::append(size_t n, char c) {
    insert(size(), n, c);
}

void MyString::append(const char *c, size_t n) {
    insert(size(), c, n);
}

void MyString::append(const char *c) {
    insert(size(), c);
}

void MyString::append(const std::string &str, size_t n) {
    insert(size(), str, n);
}

void MyString::append(const std::string &str) {
    insert(size(), str);
}

bool MyString::operator==(const MyString &s) const {
    return std::strcmp(s.data(), m_data_) == 0;
}


bool MyString::operator!=(const MyString &s) const {
    return !(*this == s);
}

bool MyString::operator<(const MyString &s) const {
   return std::strcmp(m_data_, s.data()) < 0;
}

bool MyString::operator>(const MyString &s) const {
    return std::strcmp(m_data_, s.data()) > 0;
}

bool MyString::operator>=(const MyString &s) const {
    return *this > s || *this == s;
}

bool MyString::operator<=(const MyString &s) const {
    return *this < s || *this == s;
}

MyString MyString::operator+(const MyString &s) const {
    return *this + s.data();
}

MyString MyString::operator+(const char *s) const {
    MyString result = m_data_;
    result.append(s);

    return result;
}

MyString MyString::operator+(const std::string &s) const {
    return *this + s.data();
}

MyString MyString::operator+=(const char *s) {
    *this = *this + s;
    return *this;
}
MyString MyString::operator+=(const MyString &s) {
    *this = *this + s;
    return *this;
}
MyString MyString::operator+=(const std::string &s) {
    *this = *this + s;
    return *this;
}

char &MyString::operator[](size_t pos) {
    if (pos >= m_size_) throw MyStringOutOfRangeException();

    return m_data_[pos];
}

size_t MyString::find(const char *s, size_t pos) const {
    if (pos >= m_size_) throw MyStringOutOfRangeException();
    size_t l = std::strlen(s);
    size_t res = pos;
    for (; res <= m_size_; res++) {
        bool success = true;
        for (size_t i = 0; i < l; i++) {
            if (m_data_[res + i] != s[i]) {
                success = false;
                break;
            }
        }
        if (success) return res;
    }
}

size_t MyString::find(const std::string& s, size_t pos) const {
    return find(s.c_str(), pos);
}

void MyString::replace(size_t pos, size_t n, const char *s) {
    erase(pos, n);
    insert(pos, s);
}

MyString MyString::substr(int pos, int n) {
    if (pos >= m_size_) throw MyStringOutOfRangeException();
    return MyString(m_data_ + pos, n);
}

MyString MyString::substr(int pos) {
    if (pos >= m_size_) throw MyStringOutOfRangeException();
    return MyString(m_data_ + pos);
}

std::istream &operator>>(std::istream &in, MyString &s) {
    char *buffer[IN_OP_BUFF_SIZE + 1];

    while (in) {
        in.read(reinterpret_cast<char *>(buffer), IN_OP_BUFF_SIZE);

        std::streamsize bytesRead = in.gcount();

        if (bytesRead > 0) {
            s.append(reinterpret_cast<const char *>(buffer), static_cast<std::size_t>(bytesRead));
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream &out, const MyString &s) {
    out.write(s.data(), s.size());
    return out;
}

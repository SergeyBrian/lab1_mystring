#ifndef LAB1_MYSTRING_MYSTRINGEXCEPTION_H
#define LAB1_MYSTRING_MYSTRINGEXCEPTION_H


#include <stdexcept>

class MyStringException : public std::runtime_error {
public:
    explicit MyStringException(const char *msg);
};

class MyStringOutOfRangeException : public MyStringException {
public:
    MyStringOutOfRangeException();
};


#endif //LAB1_MYSTRING_MYSTRINGEXCEPTION_H

#include "MyStringException.h"

MyStringException::MyStringException(const char *msg) : std::runtime_error(msg){}

MyStringOutOfRangeException::MyStringOutOfRangeException() : MyStringException("out_of_range") {}

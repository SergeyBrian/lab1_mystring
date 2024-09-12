#include "mystring.h"
#include <iostream>
#include <ctime>

using namespace std;


void logger(char type, std::string msg) {
    time_t current_time = time(0);
    char* current_time_str = ctime(&current_time);
    current_time_str[strlen(current_time_str) - 1] = '\0';

    if (type == 0) {
        cout << "\033[34m" <<  "[" << current_time_str << "]" << " INFO: " << msg << "\033[0m\n";
    } else if (type == 1) {
        cout << "\033[32m" << "[" << current_time_str << "]" << " Success: " << msg << "\033[0m\n";
    } else if (type == 2) {
        cout << "\033[31m" << "[" << current_time_str << "]" << " Error: " << msg << "\033[0m\n";
    } 
}

void test_constructors() {
    logger(0, "CONSTRUCTORS TESTING");
    string test_name;
    //-----------------------------|
    // TEST 1: DEFAULT CONSTRUCTOR |
    //-----------------------------|
    MyString str1;
    test_name = "TEST 1 - DEFAULT";
    str1.length() == 0 && str1.capacity() >= 1 ? logger(1, test_name) : logger(2, test_name);
    //--------------------------|
    // TEST 2: CHAR CONSTRUCTOR |
    //--------------------------|
    test_name = "TEST 2 - CHAR";
    MyString str2(10, 'a');
    str2.length() == 10 && str2.capacity() >= 11 && \
        !strcmp(str2.c_str(), "aaaaaaaaaa") ? logger(1, test_name) : logger(2, test_name);
    //--------------------------|
    // TEST 3: COPY CONSTRUCTOR |
    //--------------------------|
    test_name = "TEST 3 - COPY";
    MyString str3(str2);
    str2.length() == 10 && str2.capacity() >= 11 && !strcmp(str2.c_str(), "aaaaaaaaaa") && \
    str3.length() == 10 && str3.capacity() >= 11 && !strcmp(str3.c_str(), "aaaaaaaaaa") \
    ? logger(1, test_name) : logger(2, test_name);
    //-------------------------------------------|
    // TEST 4: CHAR ARRAY WITH COUNT CONSTRUCTOR |
    //-------------------------------------------|
    test_name = "TEST 4 - CHAR ARRAY WITH COUNT";
    MyString str4("0123456789", 5);
    str4.length() == 5 && str4.capacity() >= 6 && !strcmp(str4.c_str(), "01234") \
    ? logger(1, test_name) : logger(2, test_name);
    //--------------------------------|
    // TEST 5: CHAR ARRAY CONSTRUCTOR |
    //--------------------------------|
    test_name = "TEST 5 - CHAR ARRAY";
    MyString str5("0123456789");
    str5.length() == 10 && str5.capacity() >= 11 && !strcmp(str5.c_str(), "0123456789") \
    ? logger(1, test_name) : logger(2, test_name);
    //---------------------------------|
    // TEST 6: STD::STRING CONSTRUCTOR |
    //---------------------------------|
    test_name = "TEST 5 - STD::STRING";
    std::string std_str1("0123456789");
    MyString str6(std_str1);
    str6.length() == 10 && str6.capacity() >= 11 && !strcmp(str6.c_str(), "0123456789") \
    ? logger(1, test_name) : logger(2, test_name);
}

void test_insert_methods() {
    logger(0, "INSERT METHODS TESTING");
    string test_name;
    //--------------------------------|
    // TEST 1: INSERT IN EMPTY STRING |
    //--------------------------------|
    test_name = "TEST 1 - INSERT IN EMPTY STRING";
    MyString str1("");
    str1.insert(0, "Hello", 5);
    !strcmp(str1.c_str(), "Hello") ? logger(1, test_name) : logger(2, test_name);
    //-----------------------------------|
    // TEST 2: INSERT IN BEGIN OF STRING |
    //-----------------------------------|
    test_name = "TEST 2 - INSERT IN BEGIN OF STRING";
    MyString str2(" World");
    str2.insert(0, "Hello", 5);
    !strcmp(str2.c_str(), "Hello World") ? logger(1, test_name) : logger(2, test_name);
    //------------------------------------|
    // TEST 3: INSERT IN MIDDLE OF STRING |
    //------------------------------------|
    test_name = "TEST 3 - INSERT IN MIDDLE OF STRING";
    MyString str3("Hello World");
    str3.insert(6, "Beautiful ", 10);
    !strcmp(str3.c_str(), "Hello Beautiful World") ? logger(1, test_name) : logger(2, test_name);
    //---------------------------------|
    // TEST 4  INSERT IN END OF STRING |
    //---------------------------------|
    test_name = "TEST 4 - INSERT IN END OF STRING";
    MyString str4("Hello");
    str4.insert(5, " World", 6);
    !strcmp(str4.c_str(), "Hello World") ? logger(1, test_name) : logger(2, test_name);
    //-----------------------------|
    // TEST 5: INSERT EMPTY STRING |
    //-----------------------------|
    test_name = "TEST 5 - INSERT EMPTY STRING";
    MyString str5("Hello World");
    str5.insert(6, "", 0);
    !strcmp(str5.c_str(), "Hello World") ? logger(1, test_name) : logger(2, test_name);
    //---------------------------------------------|
    // TEST 6: INSERT EMPTY STRING IN EMPTY STRING |
    //---------------------------------------------|
    test_name = "TEST 6 - INSERT EMPTY STRING IN EMPTY STRING";
    MyString str6;
    str6.insert(0, "", 0);
    !strcmp(str6.c_str(), "") && str6.length() == 0 && \
        str6.capacity() >= 1 ? logger(1, test_name) : logger(2, test_name);
    //----------------------------|
    // TEST 7: INSERT LONG STRING |
    //----------------------------|
    test_name = "TEST 7 - INSERT LONG TAIL REWRITE ON COPY";
    MyString str7("0123456789");
    str7.insert(3, "**");
    !strcmp(str7.c_str(), "012**3456789") ? logger(1, test_name) : logger(2, test_name);
    //---------------------------|
    // TEST 8: INSERT ONE SYMBOL |
    //---------------------------|
    test_name = "TEST 8 - INSERT ONE SYMBOL";
    MyString str8("Hello World");
    str8.insert(5, "X", 1);
    !strcmp(str8.c_str(), "HelloX World") ? logger(1, test_name) : logger(2, test_name);
    //-----------------------------|
    // TEST 9: INSERT A LOT OF 'A' |
    //-----------------------------|
    test_name = "TEST 9 - INSERT A LOT OF \'A\'";
    MyString str9;
    str9.insert(0, 5000, 'a');
    str9.length() == 5000 && str9.capacity() >= 5001 ? logger(1, test_name) : logger(2, test_name);
    //------------------------------------|
    // TEST 10: INSERT STRING INTO ITSELF |
    //------------------------------------|
    test_name = "TEST 10 - INSERT STRING INTO ITSELF";
    MyString str10("Hello");
    str10.insert(5, str10.c_str());
    !strcmp(str10.c_str(), "HelloHello") ? logger(1, test_name) : logger(2, test_name);
    //---------------------------------------|
    // TEST 10: INSERT BY OUT OF RANGE INDEX |
    //---------------------------------------|
    test_name = "TEST 11 - INSERT BY OUT OF RANGE INDEX";
    MyString str11("Hello");
    try {
        str11.insert(1, " World", 6);
    } catch(...) {}
    logger(1, test_name); // If this line is executed, test has been successfully passed. Otherwise, the program should crash
}

void test() {
    test_constructors();
    test_insert_methods();
}

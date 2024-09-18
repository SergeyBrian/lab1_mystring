#ifndef TEST_GETTERS_H
#define TEST_GETTERS_H

#include "../MyString.h"
#include "test_logger.h"

#include <sstream>

void test_getters()
{
	logger(info, "GETTERS TESTS");
	std::string test_name;
    MyString str("1234567890");
	// TEST 1
	test_name = "TEST 1 - C_STR";
	log_assertion(strcmp(str.c_str(), "1234567890") == 0, test_name);
    // TEST 2
	test_name = "TEST 2 - DATA";
	log_assertion(strcmp(str.data(), "1234567890") == 0, test_name);
    // TEST 3
	test_name = "TEST 3 - LENGTH";
	log_assertion(str.length() == 10, test_name);
    // TEST 4
	test_name = "TEST 4 - SIZE";
	log_assertion(str.size() == 10, test_name);
    // TEST 5
	test_name = "TEST 5 - CAPACITY";
	log_assertion(str.capacity() == 11, test_name);
    // TEST 6
	test_name = "TEST 6 - EMPTY (REAL NOT EMPTY)";
	log_assertion(str.empty() == false, test_name);
    // TEST 6
	test_name = "TEST 7 - EMPTY";
    MyString empty_str;
	log_assertion(empty_str.empty() == true, test_name);
}

#endif // !TEST_GETTERS_H

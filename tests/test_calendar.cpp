/**
 * Unit tests for the Calendar class.
 * Compile: g++ -std=c++17 tests/test_calendar.cpp src/calendar.cpp -Iinclude -o test_calendar
 * Run:     ./test_calendar
 */
#include "../include/Calendar.h"
#include <cassert>
#include <iostream>

void test_leap_year_divisible_by_4() {
    Calendar cal(2024);
    assert(cal.isLeapYear() == true);
    std::cout << "PASS: 2024 is a leap year\n";
}

void test_century_not_leap() {
    Calendar cal(1900);
    assert(cal.isLeapYear() == false);
    std::cout << "PASS: 1900 is not a leap year (century rule)\n";
}

void test_400_year_is_leap() {
    Calendar cal(2000);
    assert(cal.isLeapYear() == true);
    std::cout << "PASS: 2000 is a leap year (400 rule)\n";
}

void test_non_leap_year() {
    Calendar cal(2023);
    assert(cal.isLeapYear() == false);
    std::cout << "PASS: 2023 is not a leap year\n";
}

void test_first_day_2024() {
    // January 1, 2024 was a Monday (index 1)
    Calendar cal(2024);
    assert(cal.getFirstDay() == 1);
    std::cout << "PASS: Jan 1, 2024 = Monday\n";
}

int main() {
    std::cout << "Running Calendar tests...\n\n";
    test_leap_year_divisible_by_4();
    test_century_not_leap();
    test_400_year_is_leap();
    test_non_leap_year();
    test_first_day_2024();
    std::cout << "\nAll tests passed.\n";
    return 0;
}

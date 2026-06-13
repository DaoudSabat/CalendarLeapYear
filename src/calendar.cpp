#include "../include/Calendar.h"
#include <iostream>
#include <iomanip>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using std::cout;
using std::string;
using std::endl;

const string Calendar::MONTH_NAMES[13] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

Calendar::Calendar(int year) : year_(year) {
    int baseDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 0; i <= 12; ++i)
        daysInMonth_[i] = baseDays[i];
    if (isLeapYear())
        daysInMonth_[2] = 29;
}

bool Calendar::isLeapYear() const {
    return (year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0);
}

int Calendar::getFirstDay() const {
    int Y = year_;
    int C = (Y - 1) / 100;
    int y = (Y - 1) % 100;
    return ((29 - 2 * C + y + y / 4 + C / 4) % 7 + 7) % 7;
}

void Calendar::setColor(int color) const {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}

void Calendar::resetColor() const {
    setColor(7);
}

void Calendar::printMonthName(int month) const {
    const string& name = MONTH_NAMES[month];
    int padding = static_cast<int>((20 - name.length()) / 2);
    cout << string(padding, ' ') << name << string(padding, ' ');
}

void Calendar::printMonth(int month, int& dayOfWeek) const {
    printMonthName(month);
    cout << "\n\n S  M  T  W  T  F  S \n--------------------\n";
    cout << string(dayOfWeek * 3, ' ');

    for (int day = 1; day <= daysInMonth_[month]; ++day) {
        if (dayOfWeek == 0) setColor(12);   // Red for Sunday
        cout << std::setw(2) << day << " ";
        if (dayOfWeek == 0) resetColor();

        if (++dayOfWeek == 7) {
            cout << "\n";
            dayOfWeek = 0;
        }
    }
    if (dayOfWeek != 0) cout << "\n";
}

void Calendar::print() const {
    cout << "       " << year_ << "\n\n";
    int dayOfWeek = getFirstDay();
    for (int month = 1; month <= 12; ++month) {
        printMonth(month, dayOfWeek);
        cout << "\n";
    }
}

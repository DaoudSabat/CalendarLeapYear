#pragma once
#include <string>

/**
 * Calendar — generates and prints a full-year calendar for any given year.
 * Highlights Sundays in red (Windows console) and handles leap years.
 */
class Calendar {
public:
    explicit Calendar(int year);

    /** Print the complete 12-month calendar to stdout. */
    void print() const;

    /** Returns true if the stored year is a leap year. */
    bool isLeapYear() const;

    /** Returns the day-of-week index (0=Sun … 6=Sat) for January 1st. */
    int getFirstDay() const;

private:
    int year_;
    int daysInMonth_[13];   // index 1-12

    static const std::string MONTH_NAMES[13];

    void printMonth(int month, int& dayOfWeek) const;
    void printMonthName(int month) const;
    void setColor(int color) const;
    void resetColor() const;
};

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

// Function prototypes
bool isLeapYear(int year);
int getFirstDay(int year);
void printMonth(int month, int& dayOfWeek, int year);
void printMonthName(int month);

// Array for days in each month (non-leap year)
int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// Array for month names
string monthNames[] = { "", "January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December" };

// Check if it's a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Calculate first day of year using given formula
int getFirstDay(int year) {
    int Y = year;
    int C = (Y - 1) / 100;  // Century
    int y = (Y - 1) % 100;  // Year within century

	// Formula for calendar
    int W = ((29 - 2 * C + y + y / 4 + C / 4) % 7 + 7) % 7;
    return W;
}

// Print a single month
void printMonth(int month, int& dayOfWeek, int year) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Print month name
    printMonthName(month);
    cout << endl<<endl;

    // Print day headers
    cout << " S  M  T  W  T  F  S " << endl;
    cout << "--------------------" << endl;

    // Print leading spaces
    int spaces = dayOfWeek * 3;
    cout << string(spaces, ' ');

    // Print days
    int days = daysInMonth[month];
    for (int day = 1; day <= days; day++) {
        // If Sunday (dayOfWeek = 0), set color to red
        if (dayOfWeek == 0) {
            SetConsoleTextAttribute(hConsole, 12);  // 12 = Red
        }

        cout << setw(2) << day << " ";

        // Reset color back to white if it was Sunday
        if (dayOfWeek == 0) {
            SetConsoleTextAttribute(hConsole, 7);  // 7 = White/Default
        }

        dayOfWeek++;

        // Start new line after Saturday (dayOfWeek = 6)
        if (dayOfWeek == 7) {
            cout << endl;
            dayOfWeek = 0;
        }
    }

    // If month doesn't end on Saturday, start new line
    if (dayOfWeek != 0) {
        cout << endl;
    }
}

// Print centered month name
void printMonthName(int month) {
    string name = monthNames[month];
    int padding = (20 - name.length()) / 2;
    cout << string(padding, ' ') << name << string(padding, ' ');
}

int main() {
    int year;

    // Get year from user
    cout << "Enter year: ";
    cin >> year;
    cout << endl;

	cout<<"       " << year << endl<<endl;
    // Adjust February for leap year
    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    // Calculate first day of the year
    int dayOfWeek = getFirstDay(year);

    // Print calendar for each month
    for (int month = 1; month <= 12; month++) {
        printMonth(month, dayOfWeek, year);
        cout << endl;
    }

}
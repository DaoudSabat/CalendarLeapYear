#include "../include/Calendar.h"
#include <iostream>

int main() {
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "\n";

    Calendar cal(year);
    cal.print();
    return 0;
}

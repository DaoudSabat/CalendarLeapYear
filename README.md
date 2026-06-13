# 📅 Calendar Leap Year

C++ console application that prints a full-year calendar for any year, with leap year detection and Sunday highlighting.

## Overview

The program prompts the user for a year, determines whether it is a leap year using the Gregorian calendar algorithm, calculates the day-of-week for January 1st, and prints all 12 months with correct alignment. Sundays are highlighted in red using the Windows console API. The core logic is encapsulated in a `Calendar` class with clear separation between rendering and calendar arithmetic.

## Architecture

```
CalendarLeapYear/
├── include/
│   └── Calendar.h         # Calendar class declaration
├── src/
│   ├── calendar.cpp       # Calendar class implementation
│   └── main.cpp           # Entry point
├── tests/
│   └── test_calendar.cpp  # Standalone test program (no framework needed)
└── CMakeLists.txt
```

## Design Patterns

- **Single Responsibility** — `Calendar` owns calendar arithmetic (`isLeapYear`, `getFirstDay`) and rendering (`print`, `printMonth`) as separate private concerns
- **Constructor Injection** — the year is injected at construction time, making `Calendar` stateless after setup and trivially testable

## Tech Stack

- **C++17**
- **Windows Console API** — `SetConsoleTextAttribute` for Sunday colour
- **CMake 3.14+** — cross-platform build system

## Installation

```bash
git clone https://github.com/DaoudSabat/CalendarLeapYear.git
cd CalendarLeapYear
cmake -B build && cmake --build build
./build/calendar
```

Or open `CalendarAssignment.sln` in Visual Studio.

## Usage

```
Enter year: 2025

       2025

        January

 S  M  T  W  T  F  S
--------------------
              1  2  3
 4  5  6  7  8  9 10
...
```

Sundays are printed in red in the Windows terminal.

## Tests

```bash
cmake --build build --target test_calendar
./build/test_calendar
```

Output:
```
Running Calendar tests...

PASS: 2024 is a leap year
PASS: 1900 is not a leap year (century rule)
PASS: 2000 is a leap year (400 rule)
PASS: 2023 is not a leap year
PASS: Jan 1, 2024 = Monday

All tests passed.
```

## License

MIT

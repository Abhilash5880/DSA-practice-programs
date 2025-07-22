#include <stdio.h>
#include <stdbool.h> // For using boolean type

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    // A year is a leap year if it is divisible by 4,
    // but not by 100, unless it is also divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a given month of a given year
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1:  // January
        case 3:  // March
        case 5:  // May
        case 7:  // July
        case 8:  // August
        case 10: // October
        case 12: // December
            return 31;
        case 4:  // April
        case 6:  // June
        case 9:  // September
        case 11: // November
            return 30;
        case 2:  // February
            return isLeapYear(year) ? 29 : 28;
        default:
            return -1; // Invalid month
    }
}

// Function to get the day of the week for the first day of the month
// (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
// This uses Zeller's Congruence algorithm
int getFirstDayOfMonth(int month, int year) {
    // Adjust month and year for Zeller's Congruence
    // January and February are counted as months 13 and 14 of the previous year
    if (month < 3) {
        month += 12;
        year--;
    }

    int K = year % 100; // Year of the century
    int J = year / 100; // Century

    // Zeller's Congruence formula
    int dayOfWeek = (1 + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;

    // Adjust result to be 0 for Sunday, 1 for Monday, etc.
    // Zeller's returns 0 for Saturday, 1 for Sunday, ..., 6 for Friday
    return (dayOfWeek + 6) % 7; // Convert to 0=Sunday, 1=Monday...
}

// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    // Array of month names
    const char *monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int daysInMonth = getDaysInMonth(month, year);
    if (daysInMonth == -1) {
        printf("Invalid month entered.\n");
        return;
    }

    int firstDay = getFirstDayOfMonth(month, year); // 0=Sunday, 1=Monday, etc.

    // Print calendar header
    printf("\n\n");
    printf("        %s %d\n", monthNames[month], year);
    printf("-----------------------------\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    printf("-----------------------------\n");

    // Print leading spaces for the first day
    for (int i = 0; i < firstDay; i++) {
        printf("    "); // 4 spaces for each empty slot
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%4d", day); // Print day with 4 spaces padding

        // Move to the next line after Saturday (or if it's the last day)
        if ((firstDay + day) % 7 == 0 || day == daysInMonth) {
            printf("\n");
        }
    }
    printf("-----------------------------\n");
}

int main() {
    int year, month;

    printf("Enter year (e.g., 2024): ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printCalendar(month, year);

    return 0;
}

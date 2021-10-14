/*
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string printDay(int day) {

    if(day % 7 == 1) return "Mon";
    if(day % 7 == 2) return "Tue";
    if(day % 7 == 3) return "Wed";
    if(day % 7 == 4) return "Thu";
    if(day % 7 == 5) return "Fri";
    if(day % 7 == 6) return "Sat";
    return "Sun";
}   

int getMaxDate(int month, int year) {

    if(month == 4 || month == 5 || month == 7 || month == 11) return 30;
    if(month == 1 || month == 3 || month == 6 || month == 8 || month == 9 || month == 10 || month == 12) return 31;
    if(year % 4 == 0) return 29;
    if(year % 100 == 0 && year % 400 == 0) return 29;
    return 28;
}

int main() {

    int date = 1;
    int day = 1;
    int month = 1;
    int year = 1900;

    int sunday_count = 0;

    while(true) {

        if(date > getMaxDate(month, year)) {
            
            cout << endl << "Month : " << month << " | Year : " << year << endl << endl;

            month ++;
            date = 1;

            if(month > 12) {

                month = 1;
                year++;

                if(year == 2001) break;
            }
        }

        if(year >= 1901) {

            if(day % 7 == 0 && date == 1) sunday_count ++;
        }

        cout << printDay(day) << " ";
        if(date % 7 == 0) cout << endl;

        date++;
        day++;
    }

    cout << sunday_count << endl;

    return 0;
}
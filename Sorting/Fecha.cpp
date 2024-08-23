#include "Fecha.h"
#include <iostream>

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int day, int month, int _year) 
: day(day), month(month), year(_year)
{
    setYear(_year);
    setMonth(month);
    Date::day = day;
}

void Date::setDay(int d) {
    int diasPorMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (d < 0) {
        day = 1;
    }
    else if (month == 2 && d == 29 && (year % 100 != 0 || year % 400 == 0)) {
        day = d;
    }
    else if (d > diasPorMes[month - 1]) {
        day = 1;
    }
    else {
        day = d;
    }
}

void Date::setMonth(int m) {
    if (m > 0 && m <= 12) {
        month = m;
    }
    else {
        month = 1;
    }
    setDay(day);
}

void Date::setYear(int y) {
    if (y >= 2000) {
        year = y;
    }
    else {
        year = 2000;
    }
    setDay(day);
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::print() {
    std::cout << day << "/" << month << "/" << year;
}

bool Date::operator<(Date& Date2) {
    if (year < Date2.year) return true;
    if (year > Date2.year) return false;
    if (month < Date2.month) return true;
    if (month > Date2.month) return false;
    if (day < Date2.day) return true;
    //if (day > Date2.day) return false;
    return false;
}

std::ostream& operator<<(std::ostream& os,Date& d) {
    os << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
    return os;
}
#include <chrono>
#include <iostream>
#include "DateManager.h"

auto now = std::chrono::system_clock::now();
std::time_t now_c = std::chrono::system_clock::to_time_t(now);
struct tm *parts = std::localtime(&now_c);

int GetCurrentDay() {
    return parts->tm_mday;
}

int GetCurrentMonth() {
    return parts->tm_mon + 1;
}

int GetCurrentYear() {
    return parts->tm_year + 1900;
}

int GetNextDay() {
    int monthLength [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = parts->tm_mday;
    int month = parts->tm_mon;

    if (monthLength[month] - (day + 7) > 0) {
        return day + 7;
    } else if (monthLength[month] - (day + 7) == 0) {
        return monthLength[month];
    } else {
        return std::abs(monthLength[month] - (day + 7));
    };
}

int GetNextMonth() {
    int monthLength [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = parts->tm_mday;
    int month = parts->tm_mon;

    if (monthLength[month] - (day + 7) > 0) {
        return month + 1;
    } else {
        if (month + 2 <= 12) {
            return month + 2;
        } else {
            return 1;
        };
    };
}

int GetNextYear() {
    int monthLength [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = parts->tm_mday;
    int month = parts->tm_mon;
    int year = parts->tm_year;

    if (monthLength[month] - (day + 7) > 0) {
        return year + 1900;
    } else {
        if (month + 2 <= 12) {
            return year + 1900;
        } else {
            return year + 1901;
        };
    };
}
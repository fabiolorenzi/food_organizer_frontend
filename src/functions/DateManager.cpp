#include <chrono>
#include <iostream>
#include "DateManager.h"

auto now = std::chrono::system_clock::now();
std::time_t now_c = std::chrono::system_clock::to_time_t(now);
struct tm *parts = std::localtime(&now_c);

const int monthLength [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day = parts->tm_mday;
int month = parts->tm_mon + 1;
int year = parts->tm_year + 1900;

int GetCurrentDay() {
    int wDay = parts->tm_wday - 1;
    if (wDay < 0) {
        wDay = 7;
    };
    if (day - wDay > 0) {
        return day - wDay;
    } else if (day - wDay < 0) {
        int temp_month = month - 1;
        if (temp_month < 1) {
            temp_month = 12;
        };
        return monthLength[temp_month] + (day - wDay);
    } else {
        return monthLength[month - 1];
    };
}

int GetCurrentMonth() {
    int wDay = parts->tm_wday - 1;
    if (wDay < 0) {
        wDay = 7;
    };
    if (day - wDay > 0) {
        return month;
    } else {
        int temp_month = month - 1;
        if (temp_month < 1) {
            temp_month = 12;
        };
        return temp_month;
    };
}

int GetCurrentYear() {
    int wDay = parts->tm_wday - 1;
    if (wDay < 0) {
        wDay = 7;
    };
    if (day - wDay > 0) {
        return year;
    } else {
        int temp_month = month - 1;
        if (temp_month < 1) {
            return year - 1;
        };
        return year;
    };
}

int GetNextDay() {
    int wDay = parts->tm_wday - 1;
    if (wDay < 0) {
        wDay = 7;
    };

    int temp_day = day - wDay + 7;
    if (temp_day <= monthLength[month]) {
        return temp_day;
    } else {
        return temp_day - monthLength[month];
    };
}

int GetNextMonth() {
    int wDay = parts->tm_wday - 1;
    if (wDay < 0) {
        wDay = 7;
    };
    
    int temp_day = day - wDay + 7;
    if (temp_day <= monthLength[month]) {
        return month;
    } else {
        return month + 1;
    };
}

int GetNextYear() {
    int wDay = parts->tm_wday - 1;
    if (wDay < 0) {
        wDay = 7;
    };
    
    int temp_day = day - wDay + 7;
    if (temp_day <= monthLength[month]) {
        return year;
    } else {
        if (month + 1 > 12) {
            return year + 1;
        } else {
            return year;
        };
    };
}
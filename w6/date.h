#pragma once

#include <string>
#include <iomanip>
#include <vector>


using namespace std;

class Date {
public:
    Date();

    Date(int new_year, int new_month, int new_day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream& stream, const Date& date);

Date ParseDate(istream& is);
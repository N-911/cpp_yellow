#pragma once

#include <string>
#include <iomanip>
#include <vector>
#include <set>


using namespace std;

class Date {
public:
    Date();

    Date(int new_year, int new_month, int new_day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

//    string Date_to_str() const;
//    operator string () const;

private:
    int year;
    int month;
    int day;
};

string Date_to_str(const Date& current_date);
Date ParseDate(istream& is);

ostream& operator<<(ostream& stream, const Date& date);
bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

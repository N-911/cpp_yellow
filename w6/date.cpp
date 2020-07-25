#include "date.h"


using namespace std;

Date :: Date() = default;

Date :: Date(int new_year, int new_month, int new_day) {

    if (new_year > 9999 || new_year < 0) {
       throw logic_error("Year value is invalid: " + to_string(new_year));
    }
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
}

int Date :: GetYear() const {
    return year;
}
int Date :: GetMonth() const {
    return month;
}
int Date :: GetDay() const {
    return day;
}


string Date_to_str(const Date& current_date) {
    return (to_string(current_date.GetYear()) + "-" + to_string(current_date.GetMonth()) + "-" + to_string(current_date.GetDay()));
}


// даты будут по умолчанию выводиться в нужном формате
ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
           "-" << setw(2) << setfill('0') << date.GetMonth() <<
           "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}


bool operator>(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}


Date ParseDate(istream& is) {
    int y;
    int m;
    int d;
    string error;
//    istringstream is(str_date);
    string str_date = "error";

    if (!(is >> y)) {
        error = "Wrong date format: " + str_date;
        throw runtime_error(error);
    }
    if (is.peek() != '-') {
        error = "Wrong date format: " + str_date;
        throw runtime_error(error);
    }
    is.ignore(1);
    if (!(is >> m)) {
        error = "Wrong date format: " + str_date;
        throw runtime_error(error);
    }
    if (is.peek() != '-') {
        error = "Wrong date format: " + str_date;
        throw runtime_error(error);
    }
    is.ignore(1);
    if (!(is >> d)) {
        error = "Wrong date format: " + str_date;
        throw runtime_error(error);
    }
//    if (!(is.peek() == EOF)) {
//        error = "Wrong date format: " + str_date;
//        throw runtime_error(error);
//    }
    return Date(y, m, d);
}



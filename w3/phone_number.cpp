#include "phone_number.h"
#include <sstream>

PhoneNumber :: PhoneNumber(const string &international_number) {
    istringstream input(international_number);

    if (input) {
        if(input.peek() != '+') {
            throw invalid_argument ("некорректный номер - не начинается на '+'" + international_number);
        }
        input.ignore(1);
        if (!(getline(input, country_code_, '-'))) {
            throw invalid_argument ("некорректный country_code_" + international_number);
        }
//        if(input.peek() != '-') {
        if (!(getline(input, city_code_, '-'))) {
            throw invalid_argument ("некорректный city_code_" + international_number);
        }
        if (!(getline(input, local_number_))) {
            throw invalid_argument ("некорректный local_number_" + international_number);
        }
    }
}

string PhoneNumber :: GetCountryCode() const {
    return country_code_;
}

string PhoneNumber :: GetCityCode() const {
    return city_code_;
}

string PhoneNumber :: GetLocalNumber() const {
    return local_number_;

}

string PhoneNumber :: GetInternationalNumber() const {
    stringstream ss;
    ss << "+" << country_code_ << "-" << city_code_ << "-" << local_number_;
    return ss.str();
//    return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}

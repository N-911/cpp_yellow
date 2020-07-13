#include "phone_number.h"
#include <iostream>


int main() {
    {
        try {
            PhoneNumber ua("+7-495-111-22-33");

            cout << ua.GetCountryCode() << " " << ua.GetCityCode() << "  " << ua.GetLocalNumber() << endl;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        }
    }
    {
        try {
            PhoneNumber ua("+7-495-1112233");

            cout << ua.GetCountryCode() << " " << ua.GetCityCode() << "  " << ua.GetLocalNumber() << endl;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        }
    }

    {
        try {
            PhoneNumber ua("+323-22-460002");

            cout << ua.GetCountryCode() << " " << ua.GetCityCode() << "  " << ua.GetLocalNumber() << endl;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        }
    }
    {
        try {
            PhoneNumber ua("+1-2-coursera-cpp");

            cout << ua.GetCountryCode() << " " << ua.GetCityCode() << "  " << ua.GetLocalNumber() << endl;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        }
    }
    {
        try {
            PhoneNumber ua("1-2-333");

            cout << ua.GetCountryCode() << " " << ua.GetCityCode() << "  " << ua.GetLocalNumber() << endl;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        }
    }
    {
        try {
            PhoneNumber ua("+7-1233");

            cout << ua.GetCountryCode() << " " << ua.GetCityCode() << "  " << ua.GetLocalNumber() << endl;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        }
    }
    return 0;
}

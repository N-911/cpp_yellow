#pragma once

#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include "date.h"
#include <stdexcept>

using namespace std;


class Database {
public:
    Database() = default;

    void Add(const Date& date, const string& event);

    string Last(const Date& date) const;

    ostream& Print(ostream& stream) const;

//    template <typename Predicate>
//    int RemoveIf(Predicate predicate);
    int RemoveIf(function<bool(const Date& date, const string& event)> predicate);
    // stable_partition

    set<string> FindIf(function<bool(const Date& date, const string& event)> predicate);


private:
    map<Date, vector<string>> storage_v;
    map<Date, set<string>> storage_s;

};
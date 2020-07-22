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

//    int RemoveIf(predicate);

    // stable_partition

//set<string> FindIf(predicate) const;



private:

map<Date, vector<string>> storage_v;
map<Date, set<string>> storage_s;

//set<Date, vector<string>> storage_2; // emplace
// vector<Date> storage   ??  or pair (2017-11-07, big sport event).

};
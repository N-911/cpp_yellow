#pragma once

#include <string>
#include <set>
#include <map>
#include <iostream>
#include "date.h"
#include <stdexcept>

using namespace std;

class Database {
public:
    Database() = default;

    void Add(const Date& date, const string& event);


    int RemoveIf(predicate);

    // stable_partition


//set<string> FindIf(predicate) const;

    ostream& Print(ostream& stream) const;

    string Last(const Date& date) const ;


private:

map<Date, vector<string>> storage;

//set<Date, vector<string>> storage_2; // emplace

// vector<Date> storage   ??  or pair (2017-11-07, big sport event).

};
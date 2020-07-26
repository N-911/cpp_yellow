#pragma once

#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <functional>

#include "date.h"

using namespace std;


class Database {
public:
    Database() = default;

    void Add(const Date& date, const string& event);

    string Last(const Date& date) const;

    ostream& Print(ostream& stream) const;
    int RemoveIf(function<bool(const Date& date, const string& event)> condition);

    vector<string> FindIf(function<bool(const Date& date, const string& event)>) const;

private:
    map<Date, vector<string>> storage_v;
    map<Date, set<string>> storage_s;
};
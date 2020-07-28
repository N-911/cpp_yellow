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
#include <sstream>

#include "date.h"

using namespace std;

struct Entry{
    Date date;
    std::string event;
};

std::ostream& operator<<(std::ostream&, const Entry&);
std::ostream& operator<<(std::ostream&, const std::vector<Entry>&);
std::ostream& operator<<(std::ostream&, const std::vector<std::string>&);

bool operator<(const Entry&, const Entry&);
bool operator>(const Entry&, const Entry&);
bool operator==(const Entry&, const Entry&);
bool operator!=(const Entry&, const Entry&);
bool operator==(const Entry&, const std::string&);
bool operator!=(const Entry&, const std::string&);


class Database {
public:
    Database() = default;

    void Add(const Date& date, const string& event);

    string Last(const Date& date) const;

    ostream& Print(ostream& stream) const;
    int RemoveIf(function<bool(const Date& date, const string& event)> predicate);

    vector<string> FindIf(function<bool(const Date& date, const string& event)>predicate) const;

private:
    map<Date, vector<string>> storage_v;
    map<Date, set<string>> storage_s;
};
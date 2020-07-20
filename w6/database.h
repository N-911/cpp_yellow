#pragma once

#include <string>
#include <set>
#include <map>
#include <iostream>
#include "date.h"


class Database {
public:


void Add(const Date& date, const string& event);

cout  ? Date Last(Date) const;

int RemoveIf(predicate) const;

set<string> FindIf(predicate) const;


void Print(ostream& stream_out) const;

private:

map<Date, set<string>> storage;

// vector<Date> storage   ??  or pair (2017-11-07, big sport event).
 };
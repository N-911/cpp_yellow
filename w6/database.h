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


class Database {
public:
    Database() = default;

    void Add(const Date& date, const string& event);

    string Last(const Date& date) const;

    ostream& Print(ostream& stream) const;
    int RemoveIf(function<bool(const Date& date, const string& event)> predicate);

//    template <typename Predicate>
//    int RemoveIf(Predicate predicate) {
//        map<Date, vector<string>> storage_v_copy = storage_v;
//        int number = 0;
//
//        for (auto item : storage_v_copy) {
//            Date date = item.first;
//            vector<string> &events = item.second;
//
//            auto it = stable_partition(events.begin(), events.end(), predicate);
//
//            number += events.end() - it;
//            events.erase(it, events.end());
//
//            if (events.size() == 0) {
//                storage_v.erase(item.first);
//                storage_s.erase(item.first);
//            } else {
//                storage_v[date] = events;
//                storage_s[date] = set<string>(events.begin(), events.end());
//            }
//        }
//        return number;
//    }

    vector<string> FindIf(function<bool(const Date& date, const string& event)>predicate) const;

private:
    map<Date, vector<string>> storage_v;
    map<Date, set<string>> storage_s;
};






#include "database.h"


void Database :: Add(const Date& date, const string& event) {
//    if (storage_s.count(date) != 0 && (storage_s[date].count(event) == 0)) {
    if ((storage_s[date].count(event) == 0)) {
        storage_v[date].push_back(event);
        storage_s[date].insert(event);
    }
}

string Database:: Last(const Date& date) const {
    if (storage_v.empty() || date < storage_v.begin()->first)
        throw invalid_argument("");

    auto up = storage_v.upper_bound(date);
    --up;
    return (Date_to_str((*up).first) + " " + *up->second.rbegin());
}
    /*
    auto it = storage_v.upper_bound(date);

    if (it != storage_v.begin()) {

//    if (it != storage_v.end()) {
//        cout << "=====" << it->first << " upper_bound(date)" << endl;
//        cout << "=====" << it->second.back() << " upper_bound(event)" << endl;
//    }
        cout << (--it)->first << " ";
        return *(--it)->second.rbegin();
    }
    else {
        throw invalid_argument("no date");
    }
}
*/

int Database :: RemoveIf(function<bool(const Date& date, const string& event)> condition) {
    int number = 0;
        map<Date, vector<string>> storage_v_copy = storage_v;

    for (auto item : storage_v_copy) {
        Date date = item.first;
        vector<string>& events = item.second;

        auto it = stable_partition(events.begin(), events.end(),
                                   [condition, date](const string &event) { return !condition(date, event); });
        number += events.end() - it;
        events.erase(it, events.end());

        if (events.size() == 0) {
            storage_v.erase(item.first);
            storage_s.erase(item.first);
        } else {
            storage_v[date] = events;
            storage_s[date] = set<string>(events.begin(), events.end());
        }
    }
    return number;
}

vector<string> Database :: FindIf(function<bool(const Date& date, const string& event)> condition) const{
    vector<string> res;

    for (const auto& date : storage_v) {
        for (const auto& ev : date.second) {
            if (condition(date.first, ev)) {
                res.push_back(Date_to_str(date.first) + " " + ev);
            }
        }
    }
    return res;
}


void Database :: Print(ostream& stream) const {
    for (const auto& [key, value] : storage_v) {
        for (const string& event : value) {
            stream << key << " " << event << endl;
        }
    }
}

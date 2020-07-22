#include "database.h"


void Database :: Add(const Date& date, const string& event) {
    if (storage_s.count(date) && (storage_s[date].count(event) == 0)) {
//        if (find(storage_s[date].begin(), storage_s[date].end(), event) == storage_s[date].end()) {
        storage_v[date].push_back(event);
        storage_s[date].insert(event);
    }
}

string Database:: Last(const Date& date) const {
    auto it = storage_v.upper_bound(date);

    if (it == storage_v.begin()) {
        throw invalid_argument("no date");
    }
    cout << (--it)->first ;
    return (--it)->second.back();
}



int Database :: RemoveIf(function<bool(const Date& date, const string& event)> predicate) {

    return 0;
}

set<string> Database :: FindIf(function<bool(const Date& date, const string& event)> predicate) {

    return {"1", " 2"};
}

/*
template <typename Predicate>
int Database :: RemoveIf(Predicate predicate){
    return 0;
}

template <typename Predicate>
set<string> Database :: FindIf(Predicate predicate) {
    set<string> res;

    return res;
}

*/


ostream& Database :: Print(ostream& stream) const {
    for (const auto& [key, value] : storage_v) {
        for (const string& event : value) {
            stream << key << event << endl;
        }
    }
    return stream;
}


/*
bool Database :: DeleteEvent(const Date& date, const string& event) {
    if (storage.count(date) > 0 && storage[date].count(event) > 0) {
        storage[date].erase(event);
            return true;
        }
        return false;
    }

int Database :: DeleteDate(const Date& date) {
    if (storage.count(date) == 0) {
        return 0;
    } else {
        const int event_count = storage[date].size();
        storage.erase(date);
        return event_count;
    }
}

set<string> Database :: Find(const Date& date) const {
    if (storage.count(date) > 0) {
        return storage.at(date);
    } else {
    return {};
    }
}
*/


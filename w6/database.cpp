#include "database.h"


void Database :: Add(const Date& date, const string& event) {
    storage[date].push_back(event);
}


string Database:: Last(const Date& date) const {

    auto it = find(begin(storage), end(storage), date);

    if (it == end(storage)) {
        throw invalid_argument("no date");
    }
    cout << (*it).first ;
    return (*it).second.back();
}


ostream& Database :: Print(ostream& stream) const {
    for (const auto& [key, value] : storage) {
        for (const string& event : value) {
            stream << key << event << endl;
        }
    }
    return stream;
}

//int Database :: RemoveIf(const Date& date, const string& event) {

//}



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


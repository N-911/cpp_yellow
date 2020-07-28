#include "database.h"

std::ostream &operator<<(std::ostream &os, const Entry &e)
{
    os << e.date << ' ' << e.event;
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<Entry> &v)
{
    for(const Entry e : v)
        os <<  e << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::string> &events)
{
    for (const std::string& ev : events){
        os << ev << " ";
    }
    return os;
}

bool operator<(const Entry &left, const Entry &right)
{
    if(left.date == right.date)
        return left.event < right.event;
    else
        return left.date < right.date;
}

bool operator>(const Entry &left, const Entry &right)
{
    if(left.date == right.date)
        return left.event > right.event;
    else
        return left.date > right.date;
}

bool operator==(const Entry &e, const std::string &str)
{
    std::stringstream ss;
    ss << e.date << ' ' << e.event;
    return (str == e.event || str == ss.str());
}

bool operator!=(const Entry &e, const std::string &str)
{
    std::stringstream ss;
    ss << e.date << ' ' << e.event;
    return (str != e.event && str != ss.str());
}

bool operator==(const Entry& left, const Entry& right)
{
    return (left.date == right.date) && (left.event == right.event);
}

bool operator!=(const Entry& left, const Entry& right)
{
    return left.date != right.date || left.event != right.event;
}

//*********************************************************************


/*
auto predicate = [condition](const Date& date, const string& event) {
                 return condition->Evaluate(date, event);
*/

//bool pred(BidirIt first, const Date &date2, function<bool(const Date& date, const string& event)> predicate) {
//    return predicate(date2, first);
//}

void Database :: Add(const Date& date, const string& event) {
//    if (storage_s.count(date) != 0 && (storage_s[date].count(event) == 0)) {
    if ((storage_s[date].count(event) == 0)) {
        storage_v[date].push_back(event);
        storage_s[date].insert(event);
    }
}

string Database:: Last(const Date& date) const {
    if (storage_v.empty() || date < storage_v.begin()->first)
        throw invalid_argument("no date");

    auto up = storage_v.upper_bound(date);
    --up;
    return (Date_to_str((*up).first) + " " + *up->second.rbegin());
}

int Database :: RemoveIf(function<bool(const Date& date, const string& event)> predicate) {
    map<Date, vector<string>> storage_v_copy = storage_v;
    int number = 0;

    for (auto item : storage_v_copy) {
        Date date = item.first;
        vector<string> &events = item.second;

        auto it = stable_partition(events.begin(), events.end(),
                                   [predicate, date](const string &event) { return !predicate(date, event); });

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

vector<string> Database :: FindIf(function<bool(const Date& date, const string& event)> predicate) const {
    vector<string> res;
    map<Date, vector<string>> storage_v_copy = storage_v;

    for (const auto& date : storage_v) {
        for (const auto& ev : date.second) {
            if (predicate(date.first, ev)) {
                res.push_back(Date_to_str(date.first) + " " + ev);
            }
        }
    }
    return res;
}

ostream& Database :: Print(ostream& stream) const {
    for (const auto& [key, value] : storage_v) {
        for (const string& event : value) {
            stream << key << " " << event << endl;
        }
    }
    return stream;
}




/*
 *     for (const auto& [key, value] : storage_v) {
        for (const string& event : value) {
            stream << key << " " << event << endl;
        }
    }

 */
























/*
 *     int number = 0;
        map<Date, vector<string>> storage_v_copy = storage_v;

    for (auto item : storage_v_copy) {
        Date date = item.first;
        vector<string>& events = item.second;

        auto it = stable_partition(events.begin(), events.end(),
                                   [condition, date](const string &event)
                                   { return !condition(date, event); });

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



 */
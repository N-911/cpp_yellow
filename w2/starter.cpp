#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string operation_code;
    is >> operation_code;

    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        int s_count;
        is >> q.bus >> s_count;
        vector<string> stops;
        for (int i = 0; i < s_count; ++i) {
            string stop;
            is >> stop;
            q.stops.push_back(stop);
        }
    } else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;

    }
    else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
  return is;
}

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) {
        cout << "No stop" << endl;
    } else {
        for (const string& bus : r.buses) {
            cout << bus << " ";
        }
    }
  return os;
}

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct AllBusesResponse {
    map<string, vector<string>> all_route;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.all_route.empty()) {
        os << "No buses" << endl;
    } else {
        for (const auto& bus_item : r.all_route) {
            os << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                os << stop << " ";
            }
            os << endl;
        }
    }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      stops_to_buses[bus] = stops;
      for (auto& stop : stops) {
          buses_to_stops[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      BusesForStopResponse res;
        if(stops_to_buses.count(stop) == 0) {
            return res;
        }
        else {
            for (const string& bus : stops_to_buses.at(stop)) {
              res.buses.push_back(bus);
            }
        }
    return res;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
      StopsForBusResponse res;
      res.bus = bus;
      res.stops.at(stops_to_buses.at(bus));
      return res;
  }

  AllBusesResponse GetAllBuses() const {
//      map<string, vector<string>> res = buses_to_stops.at();
//      return res;
      return buses_to_stops;
  }

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;

  /*
   * buses_to_stops  --> список остановок для конкретного автобуса
   * stops_to_buses  -->  список автобусов для конкретной остановки
   */
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}

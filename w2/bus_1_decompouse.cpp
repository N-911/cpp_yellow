#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <tuple>

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
        q.stops.resize(s_count);
//        vector<string>& stops = q.stops;
//        stops.resize(s_count);
        for (auto& stop : q.stops) {
            is >> stop;
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
        os << "No stop";
    } else {
        for (const string& bus : r.buses) {
            os << bus << " ";
        }
    }
  return os;
}

struct StopsForBusResponse {
    string current_bus;
    vector<pair<string, vector<string>>> v_stops;  // pair (bus, vector->stops)
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.v_stops.empty()) {
        os << "No bus";
        return os;
    }
    int count = r.v_stops.size();
    int i = 0;
    for (auto[stop, buses] : r.v_stops) {
        os << "Stop " << stop << ":";
        for (auto& bus : buses) {
            if (buses.size() == 1) {
                cout << " no interchange";
            } else {
                if (bus != r.current_bus) {
                    os << " " << bus;
                }
            }
        }
        ++i;
        if (i < count) {
            os << endl;
        }
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> all_route;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.all_route.empty()) {
        os << "No buses";
    } else {
        int count = r.all_route.size();
        int i = 0;
        for (const auto& bus_item : r.all_route) {
            os << "Bus " << bus_item.first << ":";
            for (const string& stop : bus_item.second) {
                os << " " << stop;
            }
            ++i;
            if (i < count) {
                os << endl;
            }
        }
    }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      buses_to_stops[bus] = stops;
      for (auto& stop : stops) {
          stops_to_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      BusesForStopResponse res;  // vector buses
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

      res.current_bus = bus;
      if (buses_to_stops.count(bus) == 0) {
          return res;
      }
      else {
          vector<string> stops = buses_to_stops.at(bus);
          for (auto& stop : stops) {
              BusesForStopResponse v_buses = GetBusesForStop(stop);
              res.v_stops.push_back({stop, v_buses.buses});
          }
      }
      return res;
  }

  AllBusesResponse GetAllBuses() const {
      return AllBusesResponse{buses_to_stops};
//      AllBusesResponse all;
//      all.all_route = buses_to_stops;
//      return all;
  }

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;

  /*
   * buses_to_stops  --> список остановок для конкретного автобуса
   * stops_to_buses  -->  список автобусов для конкретной остановки
   */
};

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

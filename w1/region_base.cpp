#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};


bool operator < (const Region& lhs, const Region& rhs) {
    auto l_key = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
    auto r_key = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
    return l_key < r_key;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int res = 0;

    map<Region, int> repit_map;
    for (const auto& item : regions) {
        res = max(res, ++repit_map[item]);

    }
    return res;
}


int main() {
    map<Lang, string> s{{Lang :: FR, "asdf"}};
    map<Lang, string> s1{{Lang ::DE, "asdf"}};

    cout << "compare(s, s1) =" << (s > s1) << endl;

    cout << FindMaxRepetitionCount({
    {
        "Mosco",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                89
    }, {
        "Russia",
                "Eurasia",
                {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                89
    }, {
        "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                89
    }, {
        "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                89
    }, {
        "Russia",
                "Eurasia",
                {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                89
    },
           }) << endl;

    cout << endl;
    cout << FindMaxRepetitionCount({
         {
                                               "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
         }, {
                                                   "Russia",
                                                   "Eurasia",
                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                   89
          }, {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                                                   89
          }, {
                                                   "Moscow",
                                                   "Toulouse",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                                   },
         {
                 "Moscow",
                 "Russia",
                 {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 31

         }
                                   }) << endl;
    cout << endl;
    return 0;
}


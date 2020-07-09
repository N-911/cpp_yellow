#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Предварительное объявление шаблонных функций
template <typename R>
R Sqr(const R& i);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p1, const pair<First, Second>& p2);

template <typename T>
vector<T> Sqr(const vector<T>& vector1);

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& dict);

// Объявляем шаблонные функции
template <typename R>
R Sqr(const R& i) {
    return i * i;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
    return {Sqr(p.first), Sqr(p.second)};
}

template <typename T>
vector<T> Sqr(const vector<T>& vector1) {
    vector<T> res;
    for (const auto& x : vector1) {
        res.push_back(Sqr(x));
    }
    return res;
}
template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& dict) {
    map<Key, Value> res;
    for (auto [key, value] : dict) {
        res[key] = Sqr(value);
    }
    return res;
}


int main () {
    auto p = make_pair(3, 4);
    auto res = Sqr(p);
    cout << res.first << " " << res.second << endl;
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}


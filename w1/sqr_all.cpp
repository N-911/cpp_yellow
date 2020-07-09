#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Предварительное объявление шаблонных функций

template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);

template <typename T>
vector<T> operator * (const vector<T>& vector1);

template <typename Key, typename Value>
map<Key, Value> operator * (const map<Key, Value>& dict);
// Объявляем шаблонные функции

template <typename Collection>
Collection Sqr(const Collection& col) {
    Collection res;
    for (const auto& item : col) {
        item * item;
    }
    return res;
}

template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p2.second * p2.second;
    return {f, s};
}

template <typename T>
vector<T> operator * (const vector<T>& vector1) {
    vector<T> res;
    for (const auto& x : vector1) {
        res.push_back(x * x);
    }
}
template <typename Key, typename Value>
map<Key, Value> operator * (const map<Key, Value>& dict) {
    map<Key, Value> res;
    for (auto [key, value] : dict) {
        res[key] = value * value;
    }
}



//template <typename T> // ключевое слово для объявления типа T
//T Sqr(T x) {
//    return x * x;
//     нам нужно, чтобы элемент x поддерживал операцию умножения
//}

int main () {

//    cout << Sqr(3.4) << endl;
//
    cout << "===================="/**/ << endl;
    auto p = make_pair(3, 4);
    auto res = Sqr(p);
    cout << res.first << " " << res.second << endl;
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;
/*
    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
*/
    return 0;
}
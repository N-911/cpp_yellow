#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 Напишите шаблонную функцию FindGreaterElements, принимающую множество elements объектов типа T 
 ещё один объект border типа T и возвращающую вектор из всех элементов множества, бо́льших border, 
 в возрастающем порядке.
*/


template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> res;
/*
    auto bound = find_if(
            begin(elements),
            end(elements),
            [](T elem) {return elem > border; });

    while (bound != end(elements)) {
        ++bound;
        res.push_back(*bound);
    }
    */
    for (auto it = begin(elements); it != end(elements); ++it) {
        if (*it > border) {
            res.push_back(*it);
        }
    }
    return res;
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}
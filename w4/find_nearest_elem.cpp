#include <iostream>
#include <set>
#include <iterator>

using namespace std;

set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border) {

    set<int>::const_iterator res_l = numbers.lower_bound(border);
    if (res_l == numbers.begin()) {
        return res_l;
    }
    if (res_l == numbers.end()) {
        return prev(res_l);
    }
/*
    if (res_l != numbers.begin()) {
        if (border - *prev(res_l) <= *res_l - border) {
            return prev(res_l);
        } else {
            return res_l;
        }
    }
*/
    const bool is_left = (border - *prev(res_l) <= *res_l - border);
    return is_left ? prev(res_l) : res_l;
}


int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " <<
         *FindNearestElement(numbers, 3) << " " <<
         *FindNearestElement(numbers, 5) << " " <<
         *FindNearestElement(numbers, 6) << " " <<
         *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}

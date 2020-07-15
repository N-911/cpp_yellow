#include <iostream>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border) {
    set<int>::const_iterator res_l = numbers.lower_bound(border);

//    set<int>::const_iterator res_u = numbers.upper_bound(border);
    if (res_l == numbers.begin()) {
        return res_l;
    }
    if (res_l != numbers.begin()) {
        if (border - *prev(res_l) <= *res_l - border) {
            return prev(res_l);
        } else {
            return res_l;
        }
    }
    return res_l;
}



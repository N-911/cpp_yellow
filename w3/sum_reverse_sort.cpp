#include <algorithm>
#include "sum_reverse_sort.h"

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    size_t size = s.size();

    for (size_t i = 0; i < size / 2; ++i) {
        char tmp = s[i] ;
        s[i] = s[size - i - 1];
        s[size - i - 1] = tmp;
    }
    return s;
}

void Sort(vector<int>& nums) {
    sort(begin(nums), end(nums));
}


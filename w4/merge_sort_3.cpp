#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin <  2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    RandomIt it_one = elements.begin() + elements.size() / 3;
    RandomIt it_two = elements.begin() + elements.size() * 2 / 3;

    MergeSort(elements.begin(), it_one);
    MergeSort(it_one, it_two);
    MergeSort(it_two, elements.end());
    vector<typename RandomIt::value_type> elements_temp;
    merge(elements.begin(), it_one, it_one, it_two, back_inserter(elements_temp));

    merge(elements_temp.begin(), elements_temp.end(), it_two, elements.end(), range_begin);
}

int main() {
    vector<int> v = {6, 4, 7, 1,5,9, 11,12,14};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int number;
    cin >> number;

    vector<int> v_number(number);
//    for (; number > 0; --number) {
//        v_number.push_back(number);
//    }
    iota(v_number.begin(), v_number.end(), 1);
    reverse(v_number.begin(), v_number.end());

    for (const auto& item : v_number) {
        cout << item << " ";
    }
    cout << endl;
    while(prev_permutation(v_number.begin(), v_number.end())) {
        for (const auto& item : v_number) {
            cout << item << " ";
        }
        cout << endl;
    }
}

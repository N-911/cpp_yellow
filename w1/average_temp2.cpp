#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int N;
    cin >> N;
    int average;

    int64_t sum = 0;
    vector<int> temp(N);
    vector<int> res_temp;

    for (auto& x : temp) {
        cin >> x;
        sum += x;
    }

    average = sum / N;

//    cout << "average=" << average << endl;
    int i = 0;
    for (auto item : temp) {

        if (item > average) {
            res_temp.push_back(i);
        }
        ++i;
    }
    cout << res_temp.size() << endl;
    for (auto x : res_temp) {
        cout << x << ' ';
    }

    return 0;
}

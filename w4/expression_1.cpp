#include <iostream>
#include <utility>
#include <vector>
#include <deque>


using namespace std;

int main() {

    int x, c_operation;
    cin >> x >> c_operation;

    deque<string> res;
    res.push_back(to_string(x));
    res.push_front("(");
    res.push_back(")");
    if (c_operation == 0) {
        cout << x;
        return 0;
    }
    for (int i = 0; i < c_operation; ++i) {
        int n;
        string oper;
        cin >> oper;
        cin.ignore(1);
        cin >> n;
        res.push_back({" " + oper + " " + to_string(n)});
        if ( i + 1 < c_operation) {
            res.push_front("(");
            res.push_back(")");
        }
    }
    for (auto& item : res) {
        cout << item;
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    int R;
    cin >> N >> R;

    uint64_t sum = 0;
    for (int i = 0; i < N; ++i) {
        int w, h, d;

        cin >> w >> h >> d;
        sum += static_cast<uint64_t>(w) * h * d * R;
    }
    cout << sum << endl;

    return 0;
}

#include <utility>
#include <vector>
#include <iostream>


using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix) {
    vector<typename RandomIt::value_type> s (range_begin, range_end);
//    return equal_range(s.begin(), s.end(), [] (const string& s, char prefix) { return s[0] == prefix; });

//    auto it_l = lower_bound(s.begin(), s.end(), [] (const string& s, char prefix) { return s[0] == prefix; } );
//    auto it_u = upper_bound(s.begin(), s.end(), [] (const string& s, char prefix) { return s[0] == prefix; } );
    RandomIt it_f = find_if(s.begin(), s.end(), [] (const string& s, char prefix) { return s[0] == prefix; } );
    return {it_f, it_f};
}

int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}



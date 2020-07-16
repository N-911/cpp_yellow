#include <utility>
#include <vector>
#include <iostream>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin,
        RandomIt range_end,
        char prefix) {

/*
    vector<typename RandomIt::value_type> s (range_begin, range_end);

    auto it_start = lower_bound(range_begin,
                            range_end,
                            prefix,
                            [] (const string& s, char p) { return s[0] < p; } );

    auto it_end = upper_bound(it_start,
                            range_end,
                            prefix,
                            [] (char p, const string& s) { return s[0] > static_cast<char>(p); } );

    if (it_start == range_end) {
        return {it_start, it_start};
    }
//    return {it_start, --it_end};
    return {it_start, it_end};
*/

    string s_prefix = {prefix};
    auto p = equal_range(range_begin,
                         range_end,
                         s_prefix,
                         [] (const string s1, const string s2) { return s1[0] < s2[0]; });

    return p;
}

int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "nd", "op", "ps", "vologda"};

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


//    auto it_u = upper_bound(range_begin, range_end, [p = prefix] (const string& s) { return s[0] == p; } );
//    RandomIt it_f = find_if(s.begin(), s.end(), [] (const string& s, char prefix) { return s[0] == prefix; } );

//    RandomIt it_start = lower_bound(s.begin(), s.end(), [] (const string& s ) { return s[0] == 'm'; } );
//    RandomIt it_end = upper_bound(range_begin, range_end, [] (const string& s) { return s[0] == 'm'; } );

/*  // wright answer
 * template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char prefix) {

  // Все строки, начинающиеся с '<prefix>', больше или равны строке "<prefix>"
  auto left = lower_bound(range_begin, range_end, string(1, prefix));

  // Составим следующий в алфавите символ.
  // Не страшно, если prefix = 'z':
  // в этом случае мы получим следующий за 'z' символ в таблице символов
  char next_prefix = static_cast<char>(prefix + 1);

  // Строка "<next_prefix>" в рамках буквенных строк
  // является точной верхней гранью
  // множества строк, начнающихся с '<prefix>'
  auto right = lower_bound(range_begin, range_end, string(1, next_prefix));

  return {left, right};
}

 */

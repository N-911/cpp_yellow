#include <iostream>
#include <map>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& dict, Key k) {
    if (!dict.count(k)) {
        throw runtime_error("not key");
    }
    else {
        return dict[k];
    }
}


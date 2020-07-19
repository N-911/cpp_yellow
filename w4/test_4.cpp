#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <set>
#include <functional>
// #include <cbool>


using namespace std;


bool f(int x) {
    if (x > 5) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
  set<int> s = {1,2,3,4,5};
  vector<int> v;

  auto it = remove_if(begin(s), end(s),
                    [](int x) { return !f(x); });
copy(it, end(s), back_inserter(v));


  return 0;
}
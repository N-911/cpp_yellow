#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& a) {
    if (a.empty())
        return true;
    for (size_t i = 0; i < a.size() / 2; ++i) {
        if (a[i] != a[a.size() - i - 1])
            return false;
    }
    return true;
}

//bool IsPalindrom(const string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
//}

void test_empty() {
    string a;
    Assert(IsPalindrom(a), "test empty");
    AssertEqual(IsPalindrom(" "), 1, "empty");
}

void test_one() {
    Assert(IsPalindrom("1"), "test_one");
    Assert(IsPalindrom(" "), "test_one");

}

void test_ignore_space() {
    string s;
    {
        s = " level";
        Assert(!IsPalindrom(s), "space in the begining");
    }
    {
        s = "level ";
        Assert(!IsPalindrom(s), "space in the end");
    }
    {
        s = "ma am";
        Assert(IsPalindrom(s), "spase in vord");
    }
    {
        s = "ma  am";
        Assert(IsPalindrom(s), "two space");
    }
}

void test_error(){
    Assert(!IsPalindrom("1level"s), "start compare with 2");
    Assert(!IsPalindrom("level1"), "end compare size - 2");
    Assert(!IsPalindrom("maam0caam"), "end compare < size / 2");
    Assert(!IsPalindrom("maam0ca1m"), "end compare < size / 2");
    Assert(!IsPalindrom("leve l"), "ignore space");
    Assert(!IsPalindrom("l eve  l"), "ignore space");
    Assert(!IsPalindrom("Level"), "upper case");


}
int main() {
  TestRunner runner;

  runner.RunTest(test_empty, "test_empty");
  runner.RunTest(test_one, "test_one");
  runner.RunTest(test_ignore_space, "test_ignore_space");
  runner.RunTest(test_error, "errors in function");
  return 0;
}

// 2level == true

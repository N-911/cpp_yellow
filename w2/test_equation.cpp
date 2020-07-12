#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GetDistinctRealRootCount(double a, double b, double c);


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


/*
int solve_quadratic_equation(double a , double b, double c) {
    // ax2 + bx + c = 0;
    int D = b * b - 4 * a * c;

    if (D > 0)
        return 2;
    else if (D == 0 ) {
        return 1;
    }
    else {
        return 0;
//        throw runtime_error("корней на множестве действительных чисел нет");
    }
}

int solve_linear_equation(double b, double c) {
    // bx + c = 0  x = -c/b
    if (b != 0) {
        return  1;
    } else {
        return 0;
//        throw runtime_error("division by zero");
    }
}

int GetDistinctRealRootCount(double a, double b, double c) {
    int res;

    if (a != 0) {
        res = solve_quadratic_equation(a, b, c);
    }
    else {
        res = solve_linear_equation(b, c);
    }
    return res;
}

*/
void test_a_0() {
    AssertEqual(GetDistinctRealRootCount(0, 2, 4), 1 , "test if a = 0");
    AssertEqual(GetDistinctRealRootCount(0, 0, 4), 0 ,"test if a = 0");
}

void test_d_0() {
    AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1 , "test d = 0");
}

void test_d_greater_0() {
    AssertEqual(GetDistinctRealRootCount(3, 2, -10), 2 , "test d > 0");
    AssertEqual(GetDistinctRealRootCount(19, 15, -34), 2 , "test d > 0");
    AssertEqual(GetDistinctRealRootCount(19, 15, 88), 0 , "test d > 0");

}

int main() {
    TestRunner runner;
    runner.RunTest(test_a_0, "test_a");
    runner.RunTest(test_d_0, "test_d");
    runner.RunTest(test_d_greater_0, "test_d");

  return 0;
}

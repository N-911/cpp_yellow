#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

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


/*
int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational {
public:
    Rational() {  // дробь по умолчанию — 0/1
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        // сократим дробь, разделив числитель и знаменатель на их НОД
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        // знаменатель должен быть положительным
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};


// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator(),
            lhs.Denominator() * rhs.Numerator()};
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}

*/

void test_default() {
    Rational  r;
    AssertEqual(r.Numerator(), 0, "test_default");
    AssertEqual(r.Denominator(), 1, "test_default");
}

void test_grc() {
    Rational r(2,4);
    AssertEqual(r.Numerator(), 1, "grc numerator");
    AssertEqual(r.Denominator(), 2, "grc denominator");

    Rational r1(21,12);
    AssertEqual(r1.Numerator(), 7, "grc numerator");
    AssertEqual(r1.Denominator(), 4, "grc denominator");
}

void test_negative() {
    int n, d;
    {
        n = -3;
        d = 2;
        if (n < 0 || d < 0) {
            Rational r(n, d);
            AssertEqual(r.Numerator(), -3, "Numerator test_negative");
            AssertEqual(r.Denominator(), 2, "Denominator test_negative");
        }
    }

    Rational  r1(55,-2);
    AssertEqual(r1.Numerator(), -55, "Numerator test_negative");
    AssertEqual(r1.Denominator(), 2, "Denominator test_negative");
}

void test_positive() {
    int n, d;
    {
        n = 99; d = 8;
        if (n > 0 && d > 0) {
            Rational r(n, d);
            AssertEqual(r.Numerator(), 99, "Numerator test_positive");
            AssertEqual(r.Denominator(), 8, "Denominator test_positive");
        }

    }
    {
        n = -99; d = -8;
        if (n < 0 && d < 0) {
            Rational r(n, d);
            AssertEqual(r.Numerator(), 99, "Numerator test_positive");
            AssertEqual(r.Denominator(), 8, "Denominator test_positive");
        }

    }

}

void test_default_5() {
    Rational  r(0,3);
    AssertEqual(r.Numerator(), 0, "Numerator test_default_5");
    AssertEqual(r.Denominator(), 1, "Denominator test_default_5");
}

int main() {
  TestRunner runner;
  runner.RunTest(test_default, "test_1");
  runner.RunTest(test_grc, "test_grc");
  runner.RunTest(test_negative, "test_negative");
  runner.RunTest(test_positive, "test_positive");
  runner.RunTest(test_default_5, "test_default_5");

  return 0;
}

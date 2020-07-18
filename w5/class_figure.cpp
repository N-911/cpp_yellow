#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <sstream>
#include <cmath>
#include <istream>
#include <vector>

using namespace std;

class Figure {
public:
    Figure(const string& _name) : type(_name) {}

    virtual string Name() const = 0;
    virtual float Perimeter() const = 0;
    virtual long double Area() const = 0;

    virtual ~Figure() = default;
    const string type;
};

class Triangle : public Figure {
public:
    Triangle(int& a, int& b, int& c) : Figure("TRIANGLE"), side_a(a),
                                    side_b(b), 
                                    side_c(c)
                                    {}

    string Name() const override{
        return type;
    }

    float Perimeter() const override {
        return (float(side_a) + side_b + side_c);
    }

    long double Area() const override {
        float p = (side_a + side_b + side_c) / 2.0;
        return (sqrt(p * (p - side_a) * (p - side_b) * (p - side_c)));
    }

private:
    const int side_a;
    const int side_b;
    const int side_c;
};

class Rect : public Figure {
public:
    Rect(int& w, int& h) : Figure("RECT"), width(w), height(h) {
    }

    string Name() const override {
        return type;
    }

    float Perimeter() const override {
        return float(width) * 2 + height * 2;
    }

    long double Area() const override {
        return float(width) * height;
    }

private:
    const int width;
    const int height;
};

class Circle : public Figure {
public:
    Circle(int& _radius) : Figure("CIRCLE"), radius(_radius) {}

    string Name() const override {
        return type;
    }

    float Perimeter() const override {
        return (float(radius) * 2 * 3.14);
    }

    long double Area() const override {
        return (float(radius) * radius * 3.14);
    }

private:
    int radius;
};

shared_ptr<Figure> CreateFigure(istream& is) {
    shared_ptr<Figure> res;
    string name;

    is >> name;
    if (name == "RECT") {
        int w,h;
        is >> w >> h;
        res = make_shared<Rect>(w, h);
        return res;
    }
    if (name == "TRIANGLE") {
        int a, b, c;

        is >> a >> b >>c;
        res = (make_shared<Triangle>(a, b, c));
        return res;
    }
    if (name == "CIRCLE") {
        int r;

        is >> r;
        res = (make_shared<Circle>(r));
        return res;
    }
    throw std::invalid_argument("invalid figure name was specified");
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}

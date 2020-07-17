#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <sstream>
#include <cmath>

using namespace std;

class Figure {
public:
//    Figure(const string& _name) : name(_name) {}

    virtual string Name() const = 0;
    virtual float Perimeter() const = 0;
    virtual float Area() const = 0;

};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : side_a(a), 
                                    side_b(b), 
                                    side_c(c), 
                                    name("TRIANGLE")  {}

    string Name() {
        return name;
    }

    float Perimeter() const override {
        return float(side_a) + side_b + side_c;
    }

    float Area() const override {
        int p = (side_a + side_b + side_c) / 2;
        return sqrt(p * ( p - a) * (p - b) * (p - c));
    }

private:
    const string name;
    const int side_a;
    const int side_b;
    const int side_c;
};

class Rect : public Figure {
public:
    Rect(int w, int h) : width(w), height(h), name("RECT")  {
    }

    string Name() {
        return name;
    }

    float Perimeter() const override {
        return float(width) * 2 + height * 2;
    }

    float Area() const override {
        return float(width) * height;
    }

private:
    const string name;
    const int width;
    const int height;
};

class Circle : public Figure {
public:
    Circle(int _radius) : radius(_radius), name("CIRCLE") {}


    float Perimeter() const override {
        return (float(radius) * 2 * 3.14);
    }

    float Area() const override {
        return (float(radius) * radius * 3.14);
    }

private:
    string name;
    int radius;


};

shared_ptr<Figure> CreateFigure(istream& is) {
    shared_ptr<Figure> res;





    return res;
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

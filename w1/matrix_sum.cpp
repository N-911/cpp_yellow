#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
    num_cols = 0;
    num_rows = 0;
    }

    Matrix (int new_col, int new_row) {
        num_cols = new_col;
        num_rows = new_row;
        if (new_col < 0 || new_row < 0) {
            throw out_of_range("number is negative");
        }
//        vector<vector<int>>  m(num_rows, vector<int>(num_cols));
//        matrix = m;
        matrix.resize(num_rows, vector<int>(num_cols));
    }
    void Reset(int new_col, int new_row) {
        num_cols = new_col;
        num_rows = new_row;
        if (new_col < 0 || new_row < 0) {
            throw out_of_range("number is negative");
        }
        matrix.resize(num_rows, vector<int>(num_cols));
//        matrix.assign(num_rows, );
    }
    int At(int new_col, int new_row) const {
        return matrix[new_row][new_col];
    }
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> matrix;
};

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
  Matrix one;
  Matrix two;

//  cin >> one >> two;
//  cout << one + two << endl;
  return 0;
}

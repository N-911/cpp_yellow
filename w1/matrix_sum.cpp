#include <iostream>
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;

class Matrix {
public:
    Matrix() {
        num_rows = 0;
        num_cols = 0;
    }

    Matrix (int new_row, int new_col) {
        Reset(new_row, new_col);
//        matrix.assign(num_rows, vector<int>(num_cols));
//        matrix.resize(num_rows, vector<int>(num_cols));
    }

    void Reset(int new_row, int new_col) {
        if (new_col < 0 || new_row < 0) {
            throw out_of_range("number is negative");
        }
        if (new_row == 0 || new_col == 0) {
            num_rows = 0;
            num_cols = 0;
        }
        else {
            num_rows = new_row;
            num_cols = new_col;
        }
//        matrix.resize(num_rows, vector<int>(num_cols));
        matrix.assign(num_rows, vector<int>(num_cols));
    }

    int At(int new_row, int new_col) const {
        if (new_row < 0 || new_row > num_rows) {
            throw out_of_range("new_row is negative");
        }
        if (new_col < 0 || new_col > num_cols) {
            throw out_of_range("new_col is negative");
        }
        return matrix.at(new_row).at(new_col);
    }

    int& At(int new_row, int new_col){
        if (new_row < 0 || new_row > num_rows) {
            throw out_of_range("number is negative");
        }
        if (new_col < 0 || new_col > num_cols) {
            throw out_of_range("number is negative");
        }
        return matrix.at(new_row).at(new_col);
    }

    int GetNumRows() const {
        return num_rows;
    }
    int GetNumColumns() const {
        return num_cols;
    }
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> matrix;
};


Matrix operator + (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows()) {
        throw invalid_argument ("invalid argument");
    }
    Matrix sum(lhs.GetNumRows(), lhs.GetNumColumns());

    for (size_t i = 0; i  < sum.GetNumRows(); ++i) {
        for (size_t j = 0; j < sum.GetNumColumns(); ++j) {
            sum.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return sum;
}

istream& operator >> (istream& stream, Matrix& matrix) {
    int row;
    int col;
    stream >> row;
    stream >> col;

    matrix.Reset(row, col);
    for (int i = 0; i  < row; ++i) {
        for (int j = 0; j < col; ++j) {
            stream >> matrix.At(i, j);
        }
    }
    return stream;
}

ostream& operator << (ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;

    for (int i = 0; i  < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            if (j > 0 ) {
                stream << ' ';
            }
            stream << matrix.At(i, j);
        }
        stream << endl;
    }
    return stream;
}


bool operator == (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows()) {
        return false;
    }
    for (size_t i = 0; i  < lhs.GetNumRows(); ++i) {
        for (size_t j = 0; j < lhs.GetNumColumns(); ++j) {
            if (lhs.At(i, j) != rhs.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {

    try {
//        Matrix one;
//        Matrix two;

        /*
        cin>>one>>two;
        cout << boolalpha <<(one==two)<< endl;

        cout << "test_1 OK" << endl;

        Matrix one_1;
        Matrix one_2;

        cout << (one_1 == one_2) << endl;
        cout << "test_2 OK" << endl;
        cout << one_1 + one_2 << endl;
        cout << "test_3 OK" << endl;

//        Matrix one(3, 3);
//        Matrix two(0, 0);

        one.Reset(-3, 5);
        cout << one << endl;
        cout << "test_4 OK" << endl;

        one.At(1, 1) = 3;
        cout << "test_5 OK" << endl;

        cout << two.GetNumRows() << endl;
//    cout << one;

*/
//    cin >> two;
//    cout << two;
//        Matrix sum = one + two;
//        cout << sum;

        {
            Matrix one;
            Matrix two;
            Matrix sum;
            istringstream input ("3 5\n"
                   "6 4 -1 9 8\n"
                   "12 1 2 9 -5\n"
                   "-4 0 12 8 6\n"
                   "\n"
                   "3 5\n"
                   "5 1 0 -8 23\n"
                   "14 5 -6 6 9\n"
                   "8 0 5 4 1\n"
                   "\n"
                   "3 5\n"
                   "11 5 -1 1 31\n"
                   "26 6 -4 15 4\n"
                   "4 0 17 12 7\n");

            input >> one >> two >> sum;

            bool correct = one + two == sum;
            if (!correct) {
                cout << "incorrectly answer" << (one + two) << endl;
                return 2;
            }
            else {
                cout << "OK" << endl;
            }
        }
//        sum.Reset(3, 3);
//        cout << sum;
    }
    catch (out_of_range& er) {
        cout << er.what() << endl;
    }
//    cout << one + two << endl;
    return 0;
}

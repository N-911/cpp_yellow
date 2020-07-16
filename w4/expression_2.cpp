#include <iostream>
#include <utility>
#include <vector>
#include <deque>


using namespace std;

int main() {

    int x, c_operation;
    cin >> x >> c_operation;

    deque<string> res;
    res.push_back(to_string(x));
    if (c_operation == 0) {
        cout << x;
        return 0;
    }
    int flag = 1;
    for (int i = 0; i < c_operation; ++i) {
        int n;
        string oper;
        cin >> oper;
        cin.ignore(1);
        cin >> n;

        if ( i + 1 <= c_operation && (oper == "*" || oper == "/") && !flag) {
            res.push_front("(");
            res.push_back(")");
        }
        res.push_back({" " + oper + " " + to_string(n)});
        if (oper == "+" || oper == "-") {
            flag = 0;
        } else {
            flag = 1;
        }
    }
    for (auto& item : res) {
        cout << item;
    }
    cout << endl;
    return 0;
}

/* answer!!!!!
 *
 * // Определим структуру для удобной организации данных
struct Operation {
  // Параметры по умолчанию нужны для конструирования вектора
  // ненулевого размера, см. (*)
  char type = 0;
  int number = 0;
};


// Функция для проверки выполнения требований постановки скобок
bool NeedBrackets(char last, char current) {
  return (last == '+' || last == '-') && (current == '*' || current == '/');
}


int main() {
  int initial_number;
  cin >> initial_number;

  int number_of_operations;
  cin >> number_of_operations;
  vector<Operation> operations(number_of_operations);  // (*)
  for (int i = 0; i < number_of_operations; ++i) {
    cin >> operations[i].type;
    cin >> operations[i].number;
  }

  deque<string> expression;
  expression.push_back(to_string(initial_number));
  // первое число никогда не обрамляется скобками
  char last_type = '*';
  for (const auto& operation : operations) {
    // Если условия удовлетворены, обрамляем последовательность скобками
    if (NeedBrackets(last_type, operation.type)) {
      expression.push_front("(");
      expression.push_back(")");
    }
    expression.push_back(" ");
    expression.push_back(string(1, operation.type));
    expression.push_back(" ");
    expression.push_back(to_string(operation.number));

    last_type = operation.type;
  }

  for (const string& s : expression) {
    cout << s;
  }

  return 0;
}

 */
#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& s) : Name(s){
    }

    const string Name;
};


class Dog : public Animal{
public:
    Dog(const string& a_name) : Animal (a_name){
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};


int main() {

    Dog a = Dog("ds");

    cout << a.Name << endl;
    return 0;
}

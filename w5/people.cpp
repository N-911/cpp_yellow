#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>


using namespace std;

class People {
public:

    People(const string& _name, const string& _prof) : Name(_name), 
                                                       Profesional(_prof) {}

    virtual void Walk(const string& destination) const {
        cout << Prof_and_Name() << " walks to: " << destination << endl;
    }

    const string &get_Name() const
    {
        return Name;
    }

    const string &get_Prof() const
    {
        return Profesional;
    }

    const string Prof_and_Name() const {
        return Profesional + ": " + Name;
    }

private:
    const string Name;
    const string Profesional;
};

class Student : public People {
public:

    Student(const string& name, const string& favouriteSong) : People(name, "Student"), 
                                                               FavouriteSong(favouriteSong) {

    }

    void Learn() const {
        cout << Prof_and_Name() << " learns" << endl;
    }

    void Walk(const string &destination) const {
        People :: Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << Prof_and_Name() << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};


class Teacher : public People {
public:

    Teacher(const string& name, const string& subject) : People(name, "Teacher"), Subject(subject) {
    }

    void Teach() const {
        cout << Prof_and_Name() << " teaches: " << Subject << endl;
    }

public:
    const string Subject;
};


class Policeman : public People {

public:
    Policeman(const string& name) : People(name, "Policeman") {}


    void Check(const People& p) const {
        cout << Prof_and_Name() << " checks " << p.get_Prof() << ". " << p.get_Prof() 
        << "'s name is: " << p.get_Name() << endl;
    }


};

void VisitPlaces(People& people, const vector<string>& places) {
    for (auto p : places) {
        people.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

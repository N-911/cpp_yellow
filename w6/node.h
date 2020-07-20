#pragma once

#include "date.h"
using namespace std;

/*
классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode — сформировать их иерархию 
и публичный интерфейс вам поможет анализ функций main и ParseCondition;

*/

class Node {
public :

    virtual int Evaluate() const {
        return 0;
}
};


class EmptyNode : Node {
public:
    int Evaluate(const Date& date, const string& event) const override;
};


class DateComparisonNode : Node {
public:

    DateComparisonNode(const Date& _date, char _op) {
        date = _date;
        op = _op;
    }
    
    int Evaluate(const Date& date, const string& event) const override {
        return 0;
    }

private:
    Date date;
    char op;
};


class EventComparisonNode : Node {
public:

    EventComparisonNode() = default;

};


class LogicalOperationNode : Node {
public:
    LogicalOperationNode() = default;

    int Evaluate(const Date& date, const string& event) const override {
        return 0;
    }

    void Or();
    void And();

};
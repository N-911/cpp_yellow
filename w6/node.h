#pragma once

using namespace std;

/*
классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode — сформировать их иерархию 
и публичный интерфейс вам поможет анализ функций main и ParseCondition;

*/

class Node {
public :

    virtual int Evaluate() const = 0;
}


class EmptyNode : Node {
public:
    int Evaluate() const override;
}


class DateComparisonNode : Node {
public:

    DateComparisonNode(const Date& _date, char _op) {
        date = _date;
        op = _op;
    }
    
    Evaluate(const Date& date, const string& event) {

    }

Date date;
chat op;
}

class EventComparisonNode : Node {
public:

}


class LogicalOperationNode : Node {
public:

}
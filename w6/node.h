#pragma once

#include "date.h"
#include "condition_parser.h"

using namespace std;

/*
классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode — сформировать их иерархию
и публичный интерфейс вам поможет анализ функций main и ParseCondition;

*/

class Node {
public :
    Node(const string& s_type);

    virtual int Evaluate() const;

    const string type;
};


class EmptyNode : public Node {
public:

    EmptyNode();

    int Evaluate(const Date& date, const string& event) const;

};


class DateComparisonNode : public Node {
public:

    DateComparisonNode(const Comparison& _cmp, const Date &_date);

    int Evaluate(const Date& date, const string& event) const;

private:
    Date date;
    Comparison cmp;
};


class EventComparisonNode : public Node {
public:

    EventComparisonNode(const Comparison& cmp, const string& _event);   // Comparison, event
    int Evaluate(const Date& date, const string& event) const;

private:
    string event;
    Comparison cmp;
};


class LogicalOperationNode : public Node {

public:
    LogicalOperationNode(const LogicalOperation& _lop, const shared_ptr<Node>& _left, const shared_ptr<Node>& _right);
    int Evaluate(const Date& date, const string& event) const;


private:
    LogicalOperation lop;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};
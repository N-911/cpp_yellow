#pragma once

#include "date.h"
#include "condition_parser.h"
#include <memory>

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation {
    Or,
    And
};


class Node {
public :
//    Node() = default;

    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:

    EmptyNode() = default;
    bool Evaluate(const Date& date, const string& event) const override;

};


class DateComparisonNode : public Node {
public:

    DateComparisonNode(const Comparison& _cmp, const Date& _date);
    bool Evaluate(const Date& date, const string& event) const override;

private:
    Comparison CMP;
    Date DATE;
};


class EventComparisonNode : public Node {
public:

    EventComparisonNode(const Comparison& cmp, const string& _event);   // Comparison, event
    bool Evaluate(const Date& date, const string& event) const override;

private:
    string EVENT;
    Comparison CMP;
};


class LogicalOperationNode : public Node {

public:
    LogicalOperationNode(const LogicalOperation& _lop, const shared_ptr<Node>& _left, const shared_ptr<Node>& _right);
    bool Evaluate(const Date& date, const string& event) const override;


private:
    LogicalOperation lop;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};

//template <typename Compare>
//bool template_compare(const Compare& d_1, const Compare& d_2, Comparison cmp);




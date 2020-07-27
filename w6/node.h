#pragma once

#include "date.h"
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

    virtual bool Evaluate(const Date& date, const string& event) const = 0;
    virtual ~Node() {};
};

class EmptyNode : public Node {
public:

    bool Evaluate(const Date& date, const string& event) const  override;

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
    const string EVENT;
    const Comparison CMP;
};

class LogicalOperationNode : public Node {

public:
    LogicalOperationNode(const LogicalOperation& _lop, const shared_ptr<Node>& _left, const shared_ptr<Node>& _right);
    bool Evaluate(const Date& date, const string& event) const override;


private:
    const LogicalOperation lop;
    const shared_ptr<Node> left;
    const shared_ptr<Node> right;
};

template <typename Compare>
bool ComparisonTemplate(const Compare& lhs, const Compare& rhs, const Comparison& cmp) {
    if (cmp == Comparison :: Less) {
        return lhs < rhs;
    } else if (cmp == Comparison :: LessOrEqual) {
        return lhs <= rhs;
    } else if (cmp == Comparison ::Greater) {
        return lhs > rhs;
    } else if (cmp == Comparison :: GreaterOrEqual) {
        return lhs >= rhs;
    } else if (cmp == Comparison :: Equal) {
        return lhs == rhs;
    } else if (cmp == Comparison :: NotEqual) {
        return !(lhs == rhs);
    } else {
        throw logic_error("");
    }
}
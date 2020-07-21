#include "node.h"

using namespace std;

Node :: Node(const string& s_type) : type(s_type) {}


int Node :: Evaluate() const {
    return 0;
}

EmptyNode :: EmptyNode() : Node("EmptyNode") {}

int EmptyNode ::Evaluate(const Date& date, const string& event) const {
    return 0;
}


DateComparisonNode :: DateComparisonNode(const Comparison& _cmp, const Date& _date)
                                        : Node("DateComparisonNode") {
    cmp = _cmp;
    date = _date;
}

int DateComparisonNode :: Evaluate(const Date& date, const string& event) const {
    return 0;
}


EventComparisonNode :: EventComparisonNode(const Comparison& _cmp, const string& _event)
                                            : Node("EventComparisonNode") {
    cmp = _cmp;
    event = _event;
}


LogicalOperationNode :: LogicalOperationNode(const LogicalOperation& _lop, const shared_ptr<Node>& _left,
                                             const shared_ptr<Node>& _right) : Node("LogicalOperationNode") {

    lop = _lop;
    left = _left;
    right =_right;
}
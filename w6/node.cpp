#include "node.h"

using namespace std;

//Node :: Node(const string& s_type){}


//bool Node :: Evaluate(const Date& date, const string& event) const {
//    return true;
//}

//EmptyNode :: EmptyNode() : Node("EmptyNode") {}



template <typename Compare>
bool template_compare(const Compare& d_1, const Compare& d_2, Comparison cmp) {
    if (cmp == Comparison :: Less) {
        return d_1 < d_2;
    } else if (cmp == Comparison :: LessOrEqual) {
        return d_1 <= d_2;
    } else if (cmp == Comparison ::Greater) {
        return d_1 > d_2;
    } else if (cmp == Comparison :: GreaterOrEqual) {
        return d_1 >= d_2;
    } else if (cmp == Comparison :: Equal) {
        return d_1 == d_2;
    } else if (cmp == Comparison :: NotEqual) {
        return d_1 != d_2;
    }
}

bool EmptyNode ::Evaluate(const Date& date, const string& event) const {
    return true;
}


DateComparisonNode :: DateComparisonNode(const Comparison& _cmp, const Date& _date) {
    CMP = _cmp;
    DATE = _date;
}


bool DateComparisonNode :: Evaluate(const Date& date, const string& event) const {
    return template_compare(DATE, date, CMP);
}


EventComparisonNode :: EventComparisonNode(const Comparison& _cmp, const string& _event) {
    CMP = _cmp;
    EVENT = _event;
}

bool EventComparisonNode :: Evaluate(const Date& date, const string& event) const {
    return template_compare(EVENT, event, CMP);
}

LogicalOperationNode :: LogicalOperationNode(const LogicalOperation& _lop, const shared_ptr<Node>& _left,
                                             const shared_ptr<Node>& _right) {

    lop = _lop;
    left = _left;
    right =_right;
}

bool LogicalOperationNode :: Evaluate(const Date& date, const string& event) const {

    return true;
}
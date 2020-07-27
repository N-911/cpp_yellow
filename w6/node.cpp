#include "node.h"

using namespace std;

DateComparisonNode :: DateComparisonNode(const Comparison& _cmp, const Date& _date) : CMP(_cmp), DATE(_date) {
//    CMP = _cmp;
//    DATE = _date;
}

EventComparisonNode :: EventComparisonNode(const Comparison& _cmp, const string& _event) : CMP(_cmp), EVENT(_event) {
//    CMP = _cmp;
//    EVENT = _event;
}

LogicalOperationNode :: LogicalOperationNode(const LogicalOperation& _lop, const shared_ptr<Node>& _left,
                                             const shared_ptr<Node>& _right) : lop(_lop), left(_left), right(_right){

//    lop = _lop;
//    left = _left;
//    right =_right;
}

bool EmptyNode :: Evaluate (const Date& date, const string& event) const  {
    return true;
}


bool DateComparisonNode :: Evaluate(const Date& date, const string& event) const {
    return ComparisonTemplate<Date> (date, DATE,  CMP);
}

bool EventComparisonNode :: Evaluate(const Date& date, const string& event) const {
    return ComparisonTemplate<string> (event, EVENT, CMP);
}

bool LogicalOperationNode :: Evaluate(const Date& date, const string& event) const {
    if (lop == LogicalOperation :: And) {
        return right->Evaluate(date, event) && left->Evaluate(date, event);

    } else if (lop == LogicalOperation:: Or) {
        return right->Evaluate(date, event) || left->Evaluate(date, event);
    } else {
        throw logic_error("");
    }
}


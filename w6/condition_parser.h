#pragma once

#include "node.h"
#include <iostream>

#include "token.h"
#include "date.h"
#include "node.h"
#include <map>

#include <memory>
#include <iostream>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();




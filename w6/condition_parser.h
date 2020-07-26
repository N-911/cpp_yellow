#pragma once

#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <stdexcept>
#include <istream>

#include "node.h"
#include "token.h"
#include "date.h"

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();

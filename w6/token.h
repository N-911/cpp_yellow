#pragma once

#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
  DATE,
  EVENT,
  COLUMN,       //
  LOGICAL_OP,  // AND, OR   " set - + "
  COMPARE_OP,  // ==, !=, < , > , <=, >=
  PAREN_LEFT,  // (
  PAREN_RIGHT,  // )
};

struct Token {
  const string value;
  const TokenType type;
};

vector<Token> Tokenize(istream& cl);

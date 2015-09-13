#ifndef PARSER_HPP
#define PARSER_HPP

#include "expr.hpp"
#include "token.hpp"

class Parser
{
private:
  Tokenizer &tokzer;
public:
  Expr *Parse();
};

#endif // PARSER_HPP

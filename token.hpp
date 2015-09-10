#include <istream>

class Tokenizer;

class Token
{
  friend class Tokenizer;
protected:
  std::string _textVal;

  enum Type
  {
    ch,
    nl,
    eof
  };
  Type _type;
public:

};

class Tokenizer
{
protected:
  std::istream &_in;

public:

};

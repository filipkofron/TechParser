#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <QFile>
#include <QString>
#include <QQueue>

class Tokenizer;

class Token
{
  friend class Tokenizer;

public:
  enum Type
  {
    ch,
    nl,
    eof
  };

protected:
  QString _textVal;
  Type _type;

public:
  const Type &GetType() const { return _type; }
  const QString &GetText() const { return _textVal; }
};

class Tokenizer
{
protected:
  QFile &_file;
  QQueue<char> _buffer;
public:
  Tokenizer(QFile &file);
  Token Next();
};

#endif // TOKEN_HPP

#include <iostream>
#include "token.hpp"

Tokenizer::Tokenizer(QFile &file)
  : _file(file), _saved(false)
{
}

Token Tokenizer::Next()
{
  Token ret;
  if (_saved)
  {
    _saved = false;
    return _savedToken;
  }
  if (!_buffer.size())
  {
    QByteArray bytes(1024, '\0');
    if (_file.atEnd() || !_file.isReadable() || !_file.isOpen() || !_file.read(bytes.data(), bytes.size()))
    {
      ret._type = Token::eof;
      ret._textVal = "";
      return ret;
    }
    for (qint64 i = 0; i < bytes.size(); i++)
    {
      _buffer.enqueue(bytes.at(i));
    }
  }

  switch (_buffer.head())
  {
    case '\r':
      _buffer.pop_front();
      ret._type = Token::nl;
      if (_buffer.size() && _buffer.head() == '\n')
      {
        _buffer.pop_front();
        ret._textVal = "\r\n";
      }
      else
      {
        ret._textVal = "\r";
      }
      break;
    case '\n':
      _buffer.pop_front();
      ret._type = Token::nl;
      if (_buffer.size() && _buffer.head() == '\r')
      {
        _buffer.pop_front();
        ret._textVal = "\n\r";
      }
      else
      {
        ret._textVal = "\n";
      }
      break;
    default:
      ret._textVal = (char) _buffer.dequeue();
      ret._type = Token::ch;
  }
  return ret;
}

const Token &Tokenizer::Peek()
{
  _savedToken = Next();
  _saved = true;
  return _savedToken;
}

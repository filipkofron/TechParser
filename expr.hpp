#ifndef EXPR_HPP
#define EXPR_HPP

#include <QString>

class Expr
{
protected:
public:
  virtual const QString ToString() const = 0;
  virtual Expr *Simplify() { }
};

class ExprString
{
protected:
  QString _content;
public:
  ExprString(const QString &content) : _content(content) { }
  virtual const QString ToString() const override { return _content; }
  virtual Expr *Simplify() { return new ExprString(_content); }
};

class ExprParenthesis
{
protected:
  Expr *_subExpr;
public:
  virtual const QString ToString() const override { return subExpr->ToString(); }
  virtual void Simplify() override { _subExpr->Simplify(); }
};

#endif // EXPR_HPP

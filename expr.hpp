#ifndef EXPR_HPP
#define EXPR_HPP

#include <QString>
#include <QList>

class Expr
{
protected:
public:
  virtual ~Expr() { }
  virtual const QString ToString() const = 0;
  virtual Expr *Simplify() { }
};

class ExprString : public Expr
{
protected:
  QString _content;
public:
  ExprString(const QString &content) : _content(content) { }
  virtual const QString ToString() const override { return _content; }
  virtual Expr *Simplify() { return new ExprString(_content); }
};

class ExprParenthesis : public Expr
{
protected:
  Expr *_subExpr;
public:
  ExprParenthesis(Expr *subExpr) : _subExpr(subExpr) { }
  virtual ~ExprParenthesis() { delete _subExpr; }
  virtual const QString ToString() const override { return "(" + _subExpr->ToString() + ")"; }
  virtual Expr *Simplify() override { return new ExprParenthesis(_subExpr->Simplify()); }
};

class ExprMulti
{
protected:
  QList<Expr *> _exprs;
public:
  virtual ~ExprMulti();
  ExprMulti(const QList<Expr *> &exprs) : _exprs(exprs) { }
};

#endif // EXPR_HPP

class Parser
{
private:
  bool IsWhitespace(CodeProvider &cp)
  {
    char c = cp.peek();
    return c == ' ' || c == '\t';
  }

  Expr *parse(const LineProvider &lineProvider)
  {
    CodeProvider cp = code;
    if (cp.IsEnd())
      {
        return NULL;
      }
    StringBuffer pre;
    if (isWhitespace(cp))
  }

};

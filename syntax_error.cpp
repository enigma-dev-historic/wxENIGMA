#include "syntax_error.h"

void syntax_error::set(int x, int y, int a, string s)
{
  error_sstring = s;
  err_str = error_sstring.c_str();
  line = x, position = y;
  absolute_index = a;
}

string error_sstring;
syntax_error ide_passback_error;

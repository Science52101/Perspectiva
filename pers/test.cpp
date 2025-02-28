
#include "bio.h++"
#include "vals.h++"

using namespace pers;

signed main ()
{
  vals.set_term_size({20, 20});

  bio.outln(vals.get_term_size().first);

  return 0;
}

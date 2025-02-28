#ifndef PERSPECTIVA_VALS
#define PERSPECTIVA_VALS

/****************************
*   Perspectiva - Values    *
*                           *
* Static values for the lib *
****************************/

#include <cstddef>
#include <utility>

namespace pers
{
  namespace ta
  {
    using S2D = std::pair<size_t, size_t>;
  }

  class Vals
  {
  private:

    ta::S2D term_size = {0, 0};

  public:

    void set_term_size (const ta::S2D& size)
    {
      term_size = size;
      return;
    }

    ta::S2D get_term_size (void)
    {
      return term_size;
    }

  } vals;
}

#endif

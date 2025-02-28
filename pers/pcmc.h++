#ifndef PERSPECTIVA_PCMC
#define PERSPECTIVA_PCMC

/*******************************************************
* Perspectiva - Perspectiva Character Matrix Container *
*                                                      *
* Basic container for encapsulated ASCII manipulation  *
*******************************************************/

#include <utility>

#include "vals.h++"

namespace pers
{
  class PCMC
  {
  private:
    
    char* mat;
    al::S2D size;

  public:
  
    PCMC (al::S2D size = vals.get_term_size())
    : size(size)
    {}

    PCMC (al::S2D size, const char* const mat)
    : size(size)
    {
      size_t n = size.first * size.second;

      mat = new char [n];
      std::copy(mat, mat + n, this->mat);
    }

    PCMC (PCMC& r)
    : size(r.size)
    {
      size_t n = size.first * size.second;

      mat = new char [n];
      std::copy(r.mat, r.mat + n, mat);
    }

    PCMC (PCMC&& r)
    : size(r.size)
    {
      r.size = {0, 0};
      mat = r.mat;
    }

    ~PCMC (void)
    {
      delete[] mat;
    }

    // TODO: WIP
  };
}

#endif

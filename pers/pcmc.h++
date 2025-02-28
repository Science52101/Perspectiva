#ifndef PERSPECTIVA_PCMC
#define PERSPECTIVA_PCMC

/*******************************************************
* Perspectiva - Perspectiva Character Matrix Container *
*                                                      *
* Basic container for encapsulated ASCII manipulation  *
*******************************************************/

#include <stdexcept>
#include <utility>

#include "vals.h++"
#include "bio.h++"

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

    char get_char (al::S2D pos)
    {
      if (pos.first >= size.first || pos.second >= size.second) throw std::out_of_range("Coordinates out of range.");
      return mat[pos.first * size.second + pos.second];
    }

    void output (void)
    {
      for (size_t i = 0; i < size.first; i ++)
        for (size_t j = 0; i < size.second; j ++)
          bio.out(get_char({i, j}));

      return;
    }

    // TODO: WIP
  };
}

#endif

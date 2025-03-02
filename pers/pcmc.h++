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
  protected:
    
    char* mat;
    ta::S2D size;

  public:

    PCMC (ta::S2D size = vals.get_term_size())
    : size(size)
    {
      size_t n = size.first * size.second;

      this->mat = new char [n];
    }

    PCMC (const ta::S2D& size, const char* const mat)
    : size(size)
    {
      size_t n = size.first * size.second;

      this->mat = new char [n];
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


    void set_size (const ta::S2D& nsiz = vals.get_term_size())
    {
      /* Matriz Size Setter */

      size_t n = nsiz.first * nsiz.second;

      char* nmat = new char [n];

      for (size_t i = 0; i < nsiz.first; i ++)
        for (size_t j = 0; j < nsiz.second; j ++)
          if (i < size.first && j < size.second)
            nmat[i * nsiz.second + j] = get_char({i, j});

      size = nsiz;

      char* tmp = mat;
      mat = nmat;
      delete[] tmp;

      return;
    }

    template <class ... Ts>
    void resize (Ts ... args)
    { return set_size(args ...); }

    ta::S2D get_size ()
    {
      /* Matriz Size Getter */

      return size;
    }


    char get_char (const ta::S2D& pos)
    {
      /* Specific Char Getter */

      if (pos.first >= size.first || pos.second >= size.second) throw std::out_of_range("Coordinates out of range.");

      return mat[pos.first * size.second + pos.second];
    }

    void set_char (const ta::S2D& pos, const char& c)
    {
      /* Specific Char Setter */

      if (pos.first >= size.first || pos.second >= size.second) throw std::out_of_range("Coordinates out of range.");

      mat[pos.first * size.second + pos.second] = c;

      return;
    }

    char& char_at (const ta::S2D& pos)
    {
      /* Specific Char Reference Getter */

      if (pos.first >= size.first || pos.second >= size.second) throw std::out_of_range("Coordinates out of range.");

      return mat[pos.first * size.second + pos.second];
    }

    void fill (const char& c = ' ')
    {
      /* Fill Matrix With Char */

      for (size_t i = 0; i < size.first; i ++)
        for (size_t j = 0; j < size.second; j ++)
          set_char({i, j}, c);

      return;
    }


    void output (const bool& clear = true)
    {
      /* Output Matrix */

      if (clear) bio.pout("\033[2J\033[H");

      for (size_t i = 0; i < size.first; i ++)
      {
        for (size_t j = 0; j < size.second; j ++)
          bio.pout(get_char({i, j}));
        bio.outln();
      }

      return;
    }


    // TODO: WIP
  };
}

#endif

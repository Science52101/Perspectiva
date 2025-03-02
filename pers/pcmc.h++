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
    
    char* dmat;
    char* mat;
    ta::S2D size;

  public:

    PCMC (ta::S2D size = vals.get_term_size())
    : size(size)
    {
      size_t n = size.first * size.second;

      dmat = new char [n];
      this->mat = new char [n];
    }

    PCMC (const ta::S2D& size, const char* const mat)
    : size(size)
    {
      size_t n = size.first * size.second;

      dmat = new char [n];
      this->mat = new char [n];
      std::copy(mat, mat + n, this->mat);
    }

    PCMC (PCMC& r)
    : size(r.size)
    {
      size_t n = size.first * size.second;

      dmat = new char [n];
      std::copy(r.dmat, r.dmat + n, dmat);
      mat = new char [n];
      std::copy(r.mat, r.mat + n, mat);
    }

    PCMC (PCMC&& r)
    : size(r.size)
    {
      r.size = {0, 0};
      dmat = r.dmat;
      mat = r.mat;
    }

    ~PCMC (void)
    {
      delete[] mat;
      delete[] dmat;
    }


    void set_size (const ta::S2D& nsiz = vals.get_term_size())
    {
      /* Matriz Size Setter */

      if (size == nsiz) return;

      size_t n = nsiz.first * nsiz.second;

      char* nmat;
      char* tmp;

      nmat = new char [n];

      for (size_t i = 0; i < nsiz.first; i ++)
        for (size_t j = 0; j < nsiz.second; j ++)
          if (i < size.first && j < size.second)
            nmat[i * nsiz.second + j] = get_char({i, j});

      tmp = mat;
      mat = nmat;
      delete[] tmp;

      nmat = new char [n];

      for (size_t i = 0; i < nsiz.first; i ++)
        for (size_t j = 0; j < nsiz.second; j ++)
          if (i < size.first && j < size.second)
            nmat[i * nsiz.second + j] = dmat[i * size.second + j];

      size = nsiz;

      tmp = dmat;
      dmat = nmat;
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


    bool in_range (const ta::S2D& pos)
    {
      return pos.first < size.first && pos.second < size.second;
    }


    char get_char (const ta::S2D& pos, const bool& force = false, const char& force_char = '\0')
    {
      /* Specific Char Getter */

      if (!in_range(pos))
        if (force) return force_char;
        else throw std::out_of_range("Coordinates out of range. (get_char)");

      return mat[pos.first * size.second + pos.second];
    }

    void set_char (const ta::S2D& pos, const char& c, const bool& force = false)
    {
      /* Specific Char Setter */

      if (!in_range(pos))
        if (force) return;
        else throw std::out_of_range("Coordinates out of range. (set_char)");

      mat[pos.first * size.second + pos.second] = c;

      return;
    }

    char& char_at (const ta::S2D& pos)
    {
      /* Specific Char Reference Getter */

      if (!in_range(pos)) throw std::out_of_range("Coordinates out of range. (char_at)");

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

    void set_default (void)
    {
      std::copy(mat, mat + size.first * size.second, dmat);

      return;
    }

    void reset_default (void)
    {
      std::copy(dmat, dmat + size.first * size.second, mat);

      return;
    }
  };
}

#endif

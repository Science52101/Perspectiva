#ifndef PERSPECTIVA_PCMC_TRICKS
#define PERSPECTIVA_PCMC_TRICKS

/**************************************************************
* Perspectiva - Perspectiva Character Matrix Container Tricks *
*                                                             *
*  Basic Wrapper Class With Shortcut Functions For PCMC Use   *
**************************************************************/

#include <cstddef>
#include <cstdint>
#include <cmath>
#include <stdexcept>

#include "vals.h++"
#include "anim.h++"
#include "pcmc.h++"

namespace pers
{

  class PCMCTricks
  {
    /* Utility PCMC Wrapper Class */

  protected:

    PCMC* pcmc;

  public:

    PCMCTricks (PCMC& pcmc)
    : pcmc(&pcmc)
    {}


    void write (const ta::S2D& pos, const char* str, const bool& wrap = false)
    {
      /* String/Text Plotting Function */

      ta::S2D npos = pos;

      for (; *str != '\0'; str ++)
      {
        switch (*str)
        {
        case '\n': break;

        default:
          pcmc->set_char(npos, *str, true);
        }

        if (*str == '\n' || ++ npos.second >= pcmc->get_size().second && wrap)
        {
          npos.second = pos.second;
          npos.first ++;
        }
      }

      return;
    }

    void write_del (const ta::S2D& pos, const char* str, const size_t time = 100, const bool& wrap = false)
    {
      /* String/Text Plotting Function With Per Character Delay And Output */

      ta::S2D npos = pos;

      for (; *str != '\0'; str ++)
      {
        switch (*str)
        {
        case '\n': break;

        default:
          pcmc->set_char(npos, *str, true);
        }

        if (*str == '\n' || ++ npos.second >= pcmc->get_size().second && wrap)
        {
          npos.second = pos.second;
          npos.first ++;
        }

        pcmc->output();
        anim::t_wait(time);
      }

      return;
    }


    void box_empty (ta::S2D lt, ta::S2D rb, const char& c = '#', const bool& force = false)
    {
      /* Empty Box Plotting Function */

      if (rb.first < lt.first) std::swap(lt.first, rb.first);
      if (rb.second < lt.second) std::swap(lt.second, rb.second);

      size_t d;

      if (lt.first > rb.first || lt.second > rb.second)
        if (force) return;
        else throw std::out_of_range("Right-bottom point is not before Left-top point. (box)");

      if (!pcmc->in_range(lt) || !pcmc->in_range(rb))
        if (force);
        else throw std::out_of_range("Point(s) out of range of PCMC. (box)");

      for (d = 0; d <= rb.first - lt.first; d ++)
      {
        pcmc->set_char({lt.first + d, lt.second}, c, force);
        pcmc->set_char({lt.first + d, rb.second}, c, force);
      }

      for (d = 0; d <= rb.second - lt.second; d ++)
      {
        pcmc->set_char({lt.first, lt.second + d}, c, force);
        pcmc->set_char({rb.first, lt.second + d}, c, force);
      }     

      return;
    }

    void box_fill (ta::S2D lt, ta::S2D rb, const char& c = '#', const bool& force = false)
    {
      /* Filled Box Plotting Function */

      if (rb.first < lt.first) std::swap(lt.first, rb.first);
      if (rb.second < lt.second) std::swap(lt.second, rb.second);

      if (lt.first > rb.first || lt.second > rb.second)
        if (force) return;
        else throw std::out_of_range("Right-bottom point is not before Left-top point. (box)");

      if (!pcmc->in_range(lt) || !pcmc->in_range(rb))
        if (force);
        else throw std::out_of_range("Point(s) out of range of PCMC. (box)");

      for (size_t i = 0; i <= rb.first - lt.first; i ++)
        for (size_t j = 0; j <= rb.second - lt.second; j ++)
          pcmc->set_char({lt.first + i, lt.second + j}, c, force);

      return;
    }

    void trace_line (ta::S2D lt, ta::S2D rb, const char& c = '#', const bool& force = false)
    {
      /* Single Line Plotting Function */

      // TODO: You know it must be Bresenham, even though you hate it

      long long x = lt.first,
                y = lt.second;

      long long dx = abs((long long) rb.first - lt.first),
                dy = abs((long long) rb.second - lt.second);

      char sx = (lt.first < rb.first) ? 1 : -1,
           sy = (lt.second < rb.second) ? 1 : -1;

      long long err = dx - dy,
                err2;

      while (true)
      {
        pcmc->set_char({x, y}, c, force);
        bio.errln(x, y);
        
        if (x == rb.first && y == rb.second) break;

        err2 = 2 * err;        

        if (err2 > -dy)
        {
          err -= dy;
          x += sx;
        }
        if (err2 < dx)
        {
          err += dx;
          y += sy;
        }
      }

     
      return;
    }
  };

}

#endif

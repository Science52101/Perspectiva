#ifndef PERSPECTIVA_PCMC_TRICKS
#define PERSPECTIVA_PCMC_TRICKS

/**************************************************************
* Perspectiva - Perspectiva Character Matrix Container Tricks *
*                                                             *
*  Basic Wrapper Class With Shortcut Functions For PCMC Use   *
**************************************************************/

#include "vals.h++"
#include "pcmc.h++"

namespace pers
{

  class PCMCTricks
  {
  protected:

    PCMC& pcmc;

  public:

    PCMCTricks (PCMC& pcmc)
    : pcmc(pcmc)
    {}

    void write (const ta::S2D& pos, const char* str, const bool& wrap = false)
    {
      ta::S2D npos = pos;

      for (; *str != '\0'; str ++)
      {
        pcmc.set_char(npos, *str, true);
        if (++ npos.second >= pcmc.get_size().second && wrap)
        {
          npos.second = pos.second;
          npos.first ++;
        }
      }

      return;
    }
  };

}

#endif

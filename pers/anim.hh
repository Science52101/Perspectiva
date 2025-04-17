#ifndef PERSPECTIVA_ANIM
#define PERSPECTIVA_ANIM

/****************************
* Perspectiva - Animations  *
*                           *
* Basic animation functions *
****************************/

#include <thread>
#include <chrono>
#include <iostream>

#include "bio.hh"
#include "vals.hh"

namespace pers
{
  namespace anim
  {

    void p_wait (size_t n = 1000, const bool& flush = true)
    {
      /* Wait N Process Operations */

      n *= vals.get_p_mult();
      for (size_t i = 0; i < n ; i ++)
        if (flush) bio.flush_out();
    }

    void t_wait (size_t ms = 1000, const bool& flush = true)
    {
      /* Wait N Process Operations */

      bio.flush_out();
      std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    void write (const char* str, size_t time = 100)
    {
      for (const char* c = str; *c != '\0'; c ++)
      {
        bio.out(*c);
        t_wait(time);
      }
    }

  }

}

#endif

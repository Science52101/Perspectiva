#ifndef PERSPECTIVA_ANIM
#define PERSPECTIVA_ANIM

/****************************
* Perspectiva - Animations  *
*                           *
* Basic animation functions *
****************************/

#include <iostream>

#include "vals.h++"

namespace pers
{
  namespace anim
  {

    void p_wait (size_t n = 1000)
    {
      /* Wait N Process Operations */

      n *= vals.get_p_mult();
      for (size_t i = 0; i < n ; i ++) std::cout.flush();
    }

    void write (const char* str, size_t time = 500)
    {
      for (const char* c = str; *c != '\0'; c ++)
      {
        std::cout << *c;
        p_wait(time);
      }
    }

  }

}

#endif

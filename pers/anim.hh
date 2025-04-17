#ifndef PERSPECTIVA_ANIM
#define PERSPECTIVA_ANIM

/****************************
* Perspectiva - Animations  *
*                           *
* Basic animation functions *
****************************/

#include "bio.hh"
#include "time.hh"

namespace pers
{
  namespace anim
  {

    void write (const char* str, const size_t& t = 100)
    {
      /* Print a string to the terminal with a delay between every character */

      for (const char* c = str; *c != '\0'; c ++)
      {
        bio.out(*c);
        time.t_wait(t);
      }
    }

  }

}

#endif

#ifndef PERSPECTIVA_ANIM
#define PERSPECTIVA_ANIM

/****************************
* Perspectiva - Animations  *
*                           *
* Basic animation functions *
****************************/

#include <iostream>

namespace pers
{
  namespace anim
  {

    void wait (size_t time = 1000)
    {
      time *= 10000;
      size_t cnt = 0;
      for (; cnt < time ; cnt ++) std::cout.flush();
    }

    void write (const char* str, size_t time = 500)
    {
      for (const char* c = str; *c != '\0'; c ++)
      {
        std::cout << *c;
        wait(time);
      }
    }

  }

}

#endif

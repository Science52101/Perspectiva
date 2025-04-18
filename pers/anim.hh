#ifndef PERSPECTIVA_ANIM
#define PERSPECTIVA_ANIM

/****************************
* Perspectiva - Animations  *
*                           *
* Basic animation functions *
****************************/

#include <string>

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

    void write_title (const char* str, const size_t& t = 100)
    {
      /* Print a string to the terminal with a delay between every character and a title animation */

      std::string s_aux;

      bio.pout(" ' ");
      time.t_wait(t);

      bio.pout('\r', " * ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " ** ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " *-* ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " *--* ");
      bio.flush_out();
      time.t_wait(t);

      const char* c = str;

      for (; *(c + 1) != '\0'; c ++)
      {
        s_aux.append(1u, *c);

        bio.pout('\r', " *-", s_aux, "-* ");
        bio.flush_out();
        time.t_wait(t);
      }

      s_aux.append(1u, *c);

      bio.pout('\r', " - ", s_aux, " - ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', "*  ", s_aux, "  *");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', "   ", s_aux, "   ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', "*  ", s_aux, "  *");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', "   ", s_aux, "   ");
      bio.flush_out();
      time.t_wait(t);

      bio.outln();
    }

    void write_list_item (const char* str, const size_t& t = 100)
    {
      /* Print a string to the terminal with a delay between every character and a list item animation */

      std::string s_aux;

      bio.pout(" *   ");
      time.t_wait(t);

      bio.pout('\r', "     ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " '   ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " |   ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " -|   ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " - |   ");
      bio.flush_out();
      time.t_wait(t);

      const char* c = str;

      for (; *(c + 1) != '\0'; c ++)
      {
        s_aux.append(1u, *c);

        bio.pout('\r', " - ", s_aux, "|   ");
        bio.flush_out();
        time.t_wait(t);
      }

      s_aux.append(1u, *c);

      bio.pout('\r', " - ", s_aux, " |   ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', "   ", s_aux, "  /  ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " - ", s_aux, "   - ");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', "   ", s_aux, "    *");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', " - ", s_aux, "     ");
      bio.flush_out();
      time.t_wait(t);

      bio.outln();
    }

    template <class T>
    void write_list (const size_t& n, const T* items, const size_t& t = 100)
    {
      /* Print a string to the terminal with a delay between every character and a list item animation */

      for (size_t i = 0; i < n; i ++)
        write_list_item(items[i]);
    }
    
    void wait_animation (bool dir = true, size_t mult = 5, size_t t = 500)
    {
      /* Print a string to the terminal with a delay between every character and a list item animation */

      char chs[] = {'\\', '|', '/', '-'};
      t >>= 2;

      bio.pout('\r');

      while (mult)
      {
        for (size_t i = dir ? 0 : 3; i < 4; i = dir ? i + 1 : i - 1)
        {
          bio.pout(chs[i], '\r');
          time.t_wait(t);
        }

        mult --;
      }
    }

    template <class T>
    void request_input (const char* str, T& input,  const size_t& t = 100)
    {
      /* Print a string to the terminal with a delay between every character to request an input from it. */

      std::string s_aux;

      bio.pout("*");
      time.t_wait(t);

      bio.pout('\r', "_");
      bio.flush_out();
      time.t_wait(t);

      const char* c = str;

      for (; *(c + 1) != '\0'; c ++)
      {
        s_aux.append(1u, *c);

        bio.pout('\r', s_aux, "_");
        bio.flush_out();
        time.t_wait(t);
      }

      s_aux.append(1u, *c);

      bio.pout('\r', s_aux, "-");
      bio.flush_out();
      time.t_wait(t);

      s_aux.append(1u, ' ');

      bio.pout('\r', s_aux, ">");
      bio.flush_out();
      time.t_wait(t);

      s_aux.append(1u, '(');

      bio.pout('\r', s_aux, ">");
      bio.flush_out();
      time.t_wait(t);

      c = typeid(input).name();
      for (; *c != '\0'; c ++)
      {
        s_aux.append(1u, *c);

        bio.pout('\r', s_aux, ">");
        bio.flush_out();
        time.t_wait(t);
      }

      bio.pout('\r', s_aux, ")>");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', s_aux, ") >");
      bio.flush_out();
      time.t_wait(t);

      bio.pout('\r', s_aux, ") > ");
      bio.flush_out();
      time.t_wait(t);

      bio.in(input);
    }

  }

}

#endif

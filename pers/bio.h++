#ifndef PERSPECTIVA_BIO
#define PERSPECTIVA_BIO

/***********************************
* Perspectiva - Basic Input/Output *
*                                  *
*        Basic IO functions        *
***********************************/

#include <iostream>

namespace pers
{
  class BIO
  {
  private:

    const char* o_separator;

  public:

    BIO (const char* o_separator = "\t")
    : o_separator(o_separator)
    {}

    void set_o_sep (const char* separator)
    {
      o_separator = separator;
      return;
    }

    const char* get_o_sep (void)
    {
      return o_separator;
    }

    template <class ... T>
    void out (const T& ... x)
    {
      ((std::cout << x << o_separator), ...);
    }

    template <class ... T>
    void outln (const T& ... x)
    {
      ((std::cout << x << o_separator), ...);
      std::cout << '\n';
    }


    template <class ... T>
    void err (const T& ... x)
    {
      ((std::cerr << x << o_separator), ...);
    }

    template <class ... T>
    void errln (const T& ... x)
    {
      ((std::cerr << x << o_separator), ...);
      std::cerr << '\n';
    }


    template <class ... T>
    void in (T& ... x)
    {
      ((std::cin >> x), ...);
    }

  } bio;
}

#endif

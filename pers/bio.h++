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
    /* Basic Input/Output */

  protected:

    std::istream* ins;
    std::ostream* outs;
    std::ostream* errs;
    const char* o_separator;

  public:

    BIO (std::istream& ins = std::cin, std::ostream& outs = std::cout, std::ostream& errs = std::cerr, const char* o_separator = "\t")
    : ins(&ins), outs(&outs), errs(&errs), o_separator(o_separator)
    {}

    void set_input_stream (std::istream& s)
    {
      ins = &s;

      return;
    }

    void set_output_stream (std::ostream& s)
    {
      outs = &s;

      return;
    }

    void set_error_stream (std::ostream& s)
    {
      errs = &s;

      return;
    }


    void set_o_sep (const char* separator)
    {
      /* Output Separator Setter */
      o_separator = separator;
      return;
    }

    const char* get_o_sep (void)
    {
      /* Output Separator Getter */
      return o_separator;
    }


    template <class ... T>
    void out (const T& ... x)
    {
      /* Separated Standard Output */
      ((*outs << x << o_separator), ...);
    }

    template <class ... T>
    void pout (const T& ... x)
    {
      /* Pure Standard Output */
      ((*outs << x), ...);
    }

    template <class ... T>
    void outln (const T& ... x)
    {
      /* Separated Standard Output Line */
      ((*outs << x << o_separator), ...);
      *outs << '\n';
    }


    template <class ... t>
    void err (const t& ... x)
    {
      /* Separated Error Output */
      ((*errs << x << o_separator), ...);
    }

    template <class ... t>
    void perr (const t& ... x)
    {
      /* Pure Error Output */
      ((*errs << x << o_separator), ...);
    }

    template <class ... T>
    void errln (const T& ... x)
    {
      /* Separated Error Output Line */
      ((*errs << x << o_separator), ...);
      *errs << '\n';
    }


    template <class ... T>
    void in (T& ... x)
    {
      /* Standard Input */
      ((*ins >> x), ...);
    }

  } bio;
}

#endif

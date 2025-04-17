#ifndef PERSPECTIVA_BIO
#define PERSPECTIVA_BIO

/***********************************
* Perspectiva - Basic Input/Output *
*                                  *
*        Basic IO functions        *
***********************************/

#include <cassert>
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
    const char* o_l_separator;

  public:

    BIO (std::istream& ins = std::cin, std::ostream& outs = std::cout, std::ostream& errs = std::cerr, const char* o_separator = "\t", const char* o_l_separator = "\n")
    : ins(&ins), outs(&outs), errs(&errs), o_separator(o_separator), o_l_separator(o_l_separator)
    {}

    void set_input_stream (std::istream& s)
    {
      /* Input Stream Setter */
      ins = &s;
      return;
    }

    void set_output_stream (std::ostream& s)
    {
      /* Output Stream Setter */
      outs = &s;
      return;
    }

    void set_error_stream (std::ostream& s)
    {
      /* Error Stream Setter */
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


    void set_o_l_sep (const char* separator)
    {
      /* Output Line Separator Setter */
      o_l_separator = separator;
      return;
    }

    const char* get_o_l_sep (void)
    {
      /* Output Line Separator Getter */
      return o_l_separator;
    }


    template <class ... Ts>
    void out (const Ts& ... x)
    {
      /* Separated Standard Output */
      (assert(*outs << x << o_separator), ...);
      return;
    }

    template <class ... Ts>
    void pout (const Ts& ... x)
    {
      /* Pure Standard Output */
      (assert(*outs << x), ...);
      return;
    }

    template <class ... Ts>
    void outln (const Ts& ... x)
    {
      /* Separated Standard Output Line */
      (assert(*outs << x << o_separator), ...);
      *outs << o_l_separator;
      return;
    }

    void flush_out (void)
    {
      /* Output Flushing */
      outs->flush();
      return;
    }


    template <class ... Ts>
    void err (const Ts& ... x)
    {
      /* Separated Error Output */
      (assert(*errs << x << o_separator), ...);
      return;
    }

    template <class... Ts>
    void perr (const Ts& ... x)
    {
      /* Pure Error Output */
      (assert(*errs << x << o_separator), ...);
      return;
    }

    template <class ... Ts>
    void errln (const Ts& ... x)
    {
      /* Separated Error Output Line */
      (assert(*errs << x << o_separator), ...);
      *errs << o_l_separator;
      return;
    }

    void flush_err (void)
    {
      /* Error Flushing */
      errs->flush();
      return;
    }


    template <class ... Ts>
    void in (Ts& ... x)
    {
      /* Simple Input */
      (assert(*ins >> x), ...);
      return;
    }

  } bio;
}

#endif

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


    void out (const auto& ... x)
    {
      /* Separated Standard Output */
      (assert(*outs << x << o_separator), ...);
      return;
    }

    void pout (const auto& ... x)
    {
      /* Pure Standard Output */
      (assert(*outs << x), ...);
      return;
    }

    void outln (const auto& ... x)
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



    void err (const auto& ... x)
    {
      /* Separated Error Output */
      (assert(*errs << x << o_separator), ...);
      return;
    }

    void perr (const auto& ... x)
    {
      /* Pure Error Output */
      (assert(*errs << x << o_separator), ...);
      return;
    }

    void errln (const auto& ... x)
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
    }


    void in (auto& ... x)
    {
      /* Simple Input */
      (assert(*ins >> x), ...);
      return;
    }

  } bio;
}

#endif

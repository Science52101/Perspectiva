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


    void out (const auto& ... x)
    {
      /* Separated Standard Output */
      (assert(*outs << x << o_separator), ...);
    }

    void pout (const auto& ... x)
    {
      /* Pure Standard Output */
      (assert(*outs << x), ...);
    }

    void outln (const auto& ... x)
    {
      /* Separated Standard Output Line */
      (assert(*outs << x << o_separator), ...);
      *outs << '\n';
    }

    void flush_out (void)
    {
      /* Output Flushing */
      outs->flush();
    }



    void err (const auto& ... x)
    {
      /* Separated Error Output */
      (assert(*errs << x << o_separator), ...);
    }

    void perr (const auto& ... x)
    {
      /* Pure Error Output */
      (assert(*errs << x << o_separator), ...);
    }

    void errln (const auto& ... x)
    {
      /* Separated Error Output Line */
      (assert(*errs << x << o_separator), ...);
      *errs << '\n';
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
    }

  } bio;
}

#endif

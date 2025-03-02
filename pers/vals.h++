#ifndef PERSPECTIVA_VALS
#define PERSPECTIVA_VALS

/****************************
*   Perspectiva - Values    *
*                           *
* Static values for the lib *
****************************/

#include <cstddef>
#include <utility>

#include <unistd.h>
#include <sys/ioctl.h>

namespace pers
{
  namespace ta
  {
    using S2D = std::pair<size_t, size_t>;
  }

  class Vals
  {
    /* Perspectiva Values Class */

  private:

    ta::S2D term_size;

    size_t p_mult;

  public:

    Vals ()
    {
      set_term_size();
      set_p_mult();
    }

    Vals (const ta::S2D& term_size)
    : term_size(term_size)
    {}

    ta::S2D set_term_size ()
    {
      /* Automatic Terminal Size Setter */

      struct winsize ws;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
      term_size = {ws.ws_row - 1, ws.ws_col};

      return term_size;
    }

    ta::S2D set_term_size (const ta::S2D& size)
    {
      /* Terminal Size Setter */

      term_size = size;

      return term_size;
    }

    ta::S2D get_term_size (void)
    {
      /* Terminal Size Getter */
      
      return term_size;
    }

    
    size_t get_p_mult (void) 
    {
      /* Processor Operation Multiplier Getter */

      return p_mult;
    }

    void set_p_mult (const size_t& mult = 1 << 0x10)
    {
      /* Processor Operation Multiplier Setter */

      p_mult = mult;

      return;
    }

  } vals;
}

#endif

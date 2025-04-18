#ifndef PERSPECTIVA_TIME
#define PERSPECTIVA_TIME

/****************************
* Perspectiva - Animations  *
*                           *
* Basic animation functions *
****************************/

#include <thread>
#include <chrono>

#include "bio.hh"
#include "vals.hh"

namespace pers
{
  class Time
  {
  private:

    size_t p_mult;

  public:

    Time ()
    {
      set_p_mult();
    }

    Time (const size_t& p_mult)
    : p_mult(p_mult)
    {}
    
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

    void p_wait (size_t n = 1000, const bool& flush = true)
    {
      /* Wait N Process Operations */

      n *= p_mult;
      for (size_t i = 0; i < n ; i ++)
        if (flush) bio.flush_out();
    }

    void t_wait (const size_t& ms = 1000, const bool& flush = true)
    {
      /* Wait N Process Operations */

      bio.flush_out();
      std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
  
  } time;
}

#endif

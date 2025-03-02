#include <cstdlib>

#include "bio.h++"
#include "anim.h++"
#include "pcmc.h++"
#include "pcmc_tricks.h++"

using namespace pers;

signed main ()
{
  srand(4398024);
  PCMC canvas;
  PCMCTricks tricks (canvas);

  size_t x = 0, y = 0;
  
  while (true)
  {
    canvas.resize(vals.set_term_size());

    switch (rand() % 4)
    {
    case 0:
      if (x != 0) x --;
      break;
    case 1:
      if (y != 0) y --;
      break;
    case 2:
      if (x + 1 < canvas.get_size().first) x ++;
      break;
    case 3:
      if (x + 1 < canvas.get_size().second) y += 2;
      break;
    }

    canvas.fill();
    canvas.char_at({x, y}) = '*';
    tricks.write({x, y + 1}, "Hello, World! Lorem Ipsum Dolor Sit Amet");
    tricks.write({x + 2, y + 1}, "Hello, World! Lorem Ipsum Dolor Sit Amet", true);

    canvas.output();

    anim::wait(100);
  }


  return 0;
}

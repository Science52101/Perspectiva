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
 
  canvas.fill();

  tricks.box_empty({0, 0}, {canvas.get_size().first - 1, canvas.get_size().second - 1}, '~');
  tricks.box_empty({5, 5}, {canvas.get_size().first - 6, canvas.get_size().second - 6}, '.');
  tricks.box_fill({10, 10}, {canvas.get_size().first - 11, canvas.get_size().second - 11}, '!');

  canvas.set_default();
  
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
      if (x + 1 < canvas.get_size().second) y ++;
      break;
    }

    canvas.reset_default();
   
    canvas.char_at({x, y}) = 'a' + rand() % 26;

    tricks.write({canvas.get_size().first - 10, canvas.get_size().second - 15}, "Hello, World! Lorem Ipsum Dolor Sit Amet", true);

    canvas.output();

    anim::wait(100);
  }


  return 0;
}

#include <cstdlib>

#include "bio.h++"
#include "anim.h++"
#include "pcmc.h++"
#include "pcmc_tricks.h++"

using namespace pers;

signed main ()
{
  srand(634633245524);
  PCMC canvas;
  PCMCTricks tricks (canvas);

  size_t x = canvas.get_size().first/2, y = canvas.get_size().second/2;
 
  canvas.fill();

  tricks.box_empty({5, 5}, {canvas.get_size().first - 6, canvas.get_size().second - 6}, '.');
  
  tricks.write_del({canvas.get_size().first - 10, canvas.get_size().second - 15}, "Hello, World! Lorem Ipsum Dolor Sit Amet", 5, true);

  canvas.set_as_default();
  
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

    canvas.make_default();

    tricks.trace_line({canvas.get_size().first/2, canvas.get_size().second/2}, {x, y}, '!');
   
    canvas.char_at({x, y}) = 'a' + rand() % 26;

    canvas.output();

    anim::t_wait(100);
  }


  return 0;
}

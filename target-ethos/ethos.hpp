#include <curses.h>
#include <emulator/emulator.hpp>

#include <nall/platform.hpp>
#include <nall/config.hpp>
#include <nall/directory.hpp>
#include <nall/dsp.hpp>
#include <nall/input.hpp>
#include <nall/invoke.hpp>
#include <nall/map.hpp>
#include <nall/stream/file.hpp>
#include <nall/stream/memory.hpp>
#include <nall/stream/mmap.hpp>
#include <nall/stream/vector.hpp>
using namespace nall;

#include <ruby/ruby.hpp>
using namespace ruby;

#include "configuration/configuration.hpp"
#include "interface/interface.hpp"
#include "utility/utility.hpp"
#include "input/input.hpp"
#include "resource/resource.hpp"
using namespace input;

Emulator::Interface& system();

struct Program {
  vector<Emulator::Interface*> emulator;
  Emulator::Interface* active = nullptr;
  WINDOW *window;

  bool pause;
  bool autopause;
  unsigned depth;  //color depth; 24(bpp) or 30(bpp)

  string basepath;
  string userpath;
  string sharedpath;

  string normalFont;
  string boldFont;
  string titleFont;
  string monospaceFont;

  bool focused();
  string path(string filename);
  void main();
  void bootstrap();
  void init_curses();
  Program(int argc, char** argv);
};

extern Program* program;
extern DSP dspaudio;

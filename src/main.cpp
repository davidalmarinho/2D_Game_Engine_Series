#include "Window.hpp"

int main(int argc, char const *argv[])
{
  Window window = Window("Stunner", 1024, 768);
  window.init();
  window.run();
  return 0;
}

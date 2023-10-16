#include "KeyListener.hpp"

namespace KeyListener
{
  namespace
  {
    const int NUMBER_OF_KEYS = 350;
    bool keys[NUMBER_OF_KEYS] = { false };
    bool lastKeys[NUMBER_OF_KEYS] = { false };
  }

  void update()
  {
    for (int i = 0; i < NUMBER_OF_KEYS; i++) {
      lastKeys[i] = keys[i];
    }
  }

  void key_callback(GLFWwindow* window, int keycode, int scancode, int action, int mods)
  {
    if (action == GLFW_PRESS) {
      keys[keycode] = true;
    }
    else if (action == GLFW_RELEASE) {
      keys[keycode] = false;
    }
  }

  bool isKeyPressed(int keycode)
  {
    if (keycode < NUMBER_OF_KEYS) {
      return keys[keycode];
    }

    return false;
  }

  bool isKeyDown(int keycode)
  {
    if (keycode < NUMBER_OF_KEYS) {
      return keys[keycode] && !lastKeys[keycode];
    }

    return false;
  }

  bool isKeyUp(int keycode)
  {
    if (keycode < NUMBER_OF_KEYS) {
      return !keys[keycode] && lastKeys[keycode];
    }

    return false;
  }
}
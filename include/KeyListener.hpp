#pragma once

#include <GLFW/glfw3.h>

namespace KeyListener
{
  void key_callback(GLFWwindow* window, int keycode, int scancode, int action, int mods);

  void update();

  // Action when holding key.
  bool isKeyPressed(int keycode);

  // Action when pressing the key.
  bool isKeyDown(int keycode);

  // Action when releasing the key.
  bool isKeyUp(int keycode);

  // Homework
  bool isKeyBindDown(int modKey, int keyCode);
}
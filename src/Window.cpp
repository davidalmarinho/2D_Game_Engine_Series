#include "Window.hpp"
#include "KeyListener.hpp"
#include "Utils.hpp"

#include <iostream>
#include <string>

Window::Window()
{

}

Window::Window(std::string name, int width, int height)
{
  this->name   = name;
  this->width  = width;
  this->height = height;
}

void Window::init()
{
  if (glfwInit() == GLFW_FALSE) {
    std::cerr << "Error: Couldn't initialize GLFW lib.\n";
  }

  // Configure the window.
  glfwDefaultWindowHints();
  glfwWindowHint(GLFW_VISIBLE, GL_TRUE);

  // Good practice and makes the glfw and OpenGL more compatible with Linux operating system. 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // A context can be created with any OpenGL 3.x version.
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2); // A context needs to be created with at least 3.2 OpenGL version.
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Use the core profile of OpenGL, which includes only the most modern and forward-compatible features of the specified OpenGL version.
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Sets a hint for GLFW to enable forward compatibility for the OpenGL context -- Forward compatibility means that the OpenGL context will not support any deprecated features.

  // Create the window.
  this->glfwWindow = glfwCreateWindow(this->width, this->height, this->name.c_str(), NULL, NULL);
  if (!glfwWindow) {
    std::cerr << "Error: GLFW window couldn't be created.\n";
  }

  // Tell the glfw how to handle the keyboard input.
  glfwSetKeyCallback(this->glfwWindow, KeyListener::key_callback);
}

void Window::run()
{
  std::string fileCont = Utils::readFile("assets/file.txt");
  std::cout << fileCont << std::endl;

  while(!glfwWindowShouldClose(this->glfwWindow)) {
    // Running...


    KeyListener::update();
    glfwPollEvents();
  }
  this->cleanup();
}

void Window::cleanup()
{
  glfwDestroyWindow(this->glfwWindow);
}
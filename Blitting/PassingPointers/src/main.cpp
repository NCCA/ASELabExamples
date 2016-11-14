#include <cstdlib>
#include <cstring>
#include <chrono>
#include <thread>
#include <array>
#include <iostream>
#include <string>
#include <random>
#include "Framebuffer.h"
#include "Image.h"
#include "Vec2.h"
#include "Emitter.h"

GLFWwindow* gWindowPointer;
std::unique_ptr<Emitter> emitter;
// custom key callback
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);


int main()
{
    std::unique_ptr<frm::Framebuffer> framebuffer( new frm::Framebuffer());
    size_t width=1024;
    size_t height=720;
    gWindowPointer=framebuffer->init(width, height, (void*)99);
    glfwSetKeyCallback(gWindowPointer, keyCallback);

    Image image(width,height);
    image.setBackground(255,255,255);

    framebuffer->bind();
    framebuffer->poll();

    framebuffer->title("Particle");
    Vec2<int> pos(width/2,height/2);
    Vec2<int> dir(1,1);
    emitter.reset(new  Emitter(pos,20000));
    while(!framebuffer->shouldClose())
    {
      image.setBackground(255,255,255);
      emitter->update();
      emitter->draw(image);
      framebuffer->image(image.get(),width,height);
      framebuffer->draw();
      framebuffer->poll();

    }


  return EXIT_SUCCESS;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    switch(key)
    {
      case GLFW_KEY_ESCAPE:
        std::cout<< "exiting";
        exit(EXIT_SUCCESS);
      break;
      case GLFW_KEY_UP :
        emitter->moveY(-5);
      break;
    case GLFW_KEY_DOWN :
      emitter->moveY(5);
    break;
    case GLFW_KEY_LEFT :
      emitter->moveX(-5);
    break;
    case GLFW_KEY_RIGHT :
      emitter->moveX(5);
    break;

    default: break;

  }
}









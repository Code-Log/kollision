#include <exception>
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "graphics/renderer.h"
#include "graphics/DrawableContext.h"
#include "graphics/drawable.h"
#include "graphics/rectangle.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

GLFWwindow* window;
glm::mat4 mvp;

using namespace kollision;

void init() {

    auto* rect = new Rectangle(200, 100, 0, 0);
    DrawableContext::getInstance().addDrawable(rect);

    DrawableContext::getInstance().getDrawables().for_each([](Drawable*& d) {
        d->init();
    });

}

void loop() {

    glClearColor(255, 0, 0, 255);
    glClear(GL_COLOR_BUFFER_BIT);

    mvp = glm::ortho(0, 800, 600, 0, 0, 1);

    DrawableContext::getInstance().getDrawables().for_each([](Drawable*& d) {
        d->draw(mvp);
    });

}

int main() {

    glewExperimental = true;

    if (!glfwInit()) {
        std::cerr << "Couldn't initialize GLFW!" << std::endl;
        throw std::exception();
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "Window", nullptr, nullptr);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

    glfwMakeContextCurrent(window);

    if (glewInit() != 0) {
        std::cerr << "Couldn't initialize GLEW!" << std::endl;
        throw std::exception();
    }

    glEnable(GL_BLEND);
//    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_MULTISAMPLE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glDepthFunc(GL_LEQUAL);

    init();

    while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {

        loop();

        glfwPollEvents();
        glfwSwapBuffers(window);

    }

    glfwDestroyWindow(window);
    glfwTerminate();

}
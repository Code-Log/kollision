#include <exception>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "graphics/renderer.h"
#include "graphics/rectangle.h"

using namespace kollision;

auto main() -> int {

    glewExperimental = true;

    if (!glfwInit()) {
        std::cerr << "Couldn't initialize GLFW!" << std::endl;
        throw std::exception();
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto* window = glfwCreateWindow(800, 600, "Physics", nullptr, nullptr);

    Renderer renderer(window, 800, 600);
    renderer.init();

    auto* rect = new Rectangle(200, 100, glm::vec2(0, 0));
    rect->init();
    renderer.addDrawable(rect);

    while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {

        renderer.renderFrame();

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();

}
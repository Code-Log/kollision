#include "renderer.h"
#include <exception>
#include <glm/gtc/matrix_transform.hpp>

namespace kollision {

    Renderer::Renderer(GLFWwindow *window, int width, int height)
        : m_Window(window), m_Drawables(10), m_Height(height), m_Width(width),
        m_MVP(glm::ortho(0.0f, (float)m_Width, (float)m_Height, 0.0f))
    {
    }

    void Renderer::init() {

        glfwMakeContextCurrent(m_Window);

        if (glewInit() != 0)
            throw std::exception();

        glfwSetInputMode(m_Window, GLFW_STICKY_KEYS, GLFW_TRUE);

        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_MULTISAMPLE);

        glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        glDepthFunc(GL_ALWAYS);

    }

    void Renderer::addDrawable(Drawable *drawable) { m_Drawables.push_back(drawable); }

    void Renderer::renderFrame() {

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClearDepth(1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (int i = 0; i < m_Drawables.size(); i++) {
            m_Drawables[i]->draw(m_MVP);
        }

    }

}
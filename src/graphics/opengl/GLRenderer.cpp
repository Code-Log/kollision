#include "GLRenderer.h"
#include <exception>
#include <glm/gtc/matrix_transform.hpp>

namespace kollision {

    GLFWwindow* GLRenderer::WINDOW = nullptr;
    bool GLRenderer::ENABLE_RENDERER = false;
    GLRenderer* GLRenderer::instance = nullptr;

    GLRenderer::GLRenderer(GLFWwindow *window)
        : m_Window(window), m_Drawables(10), m_Height(0), m_Width(0),
        m_MVP(glm::mat4(1.0f))
    {

        glfwGetWindowSize(m_Window, &m_Width, &m_Height);
        struct invalid_dimensions_exception : public std::exception {
            const char* what() const noexcept override {
                return "Invalid window dimensions!";
            }
        };

        if (m_Width <= 0 || m_Height <= 0)
            throw invalid_dimensions_exception();

        m_MVP = glm::ortho(0.0f, (float)m_Width, (float)m_Height, 0.0f);
        ENABLE_RENDERER = true;
//        setRenderer(this);

    }

    GLRenderer& GLRenderer::get() {
        instance = (instance == nullptr) ? new GLRenderer(WINDOW) : instance;
        return *instance;
    }

    void GLRenderer::removeDrawable(Drawable *drawable) {
        for (int i = m_Drawables.size() - 1; i >= 0; i--) {
            if (drawable)
                if (drawable == m_Drawables[i])
                    m_Drawables.erase(i, 1);
        }
    }

    void GLRenderer::addRenderListener(RenderListener* listener) {
        m_Listeners.push_back(listener);
    }

    void GLRenderer::init() {

        glfwMakeContextCurrent(m_Window);

        if (glewInit() != 0)
            throw std::exception();

        glfwSetInputMode(m_Window, GLFW_STICKY_KEYS, GLFW_TRUE);

        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_MULTISAMPLE);

        glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        glDepthFunc(GL_ALWAYS);

        m_Listeners.for_each([](RenderListener*& listener) { listener->setup(); });

    }

    void GLRenderer::addDrawable(Drawable *drawable) {
        drawable->init();
        m_Drawables.push_back(drawable);
    }

    void GLRenderer::renderFrame() {

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClearDepth(1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (int i = 0; i < m_Drawables.size(); i++) {
            m_Drawables[i]->draw(m_MVP);
        }

        m_Listeners.for_each([](RenderListener*& listener) { listener->draw(); });

    }

    void GLRenderer::start() {

        while (!glfwWindowShouldClose(m_Window) && glfwGetKey(m_Window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {

            this->renderFrame();

            glfwPollEvents();
            glfwSwapBuffers(m_Window);

        }

    }

}
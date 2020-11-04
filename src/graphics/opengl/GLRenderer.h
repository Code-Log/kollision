#ifndef KOLLISION_GLRENDERER_H
#define KOLLISION_GLRENDERER_H

#pragma once

#include <clstl/vector.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../drawable.h"
#include "../Renderer.h"

namespace kollision {

    class RenderListener {
    public:
        virtual void setup() = 0;
        virtual void draw() = 0;
    };

    class GLRenderer : public Renderer {
    private:
        GLFWwindow* m_Window;
        int m_Width, m_Height;
        glm::mat4 m_MVP;
        clstl::vector<Drawable*> m_Drawables;
        clstl::vector<RenderListener*> m_Listeners;

        explicit GLRenderer(GLFWwindow* window);

    public:
        static GLRenderer* instance;
        static bool ENABLE_RENDERER;
        static GLFWwindow* WINDOW;

        static GLRenderer& get();

        void init() override;
        void addDrawable(Drawable* drawable) override;
        void removeDrawable(Drawable* drawable) override;
        void renderFrame() override;
        void start() override;
        void addRenderListener(RenderListener* listener);

        void operator=(const GLRenderer&) = delete;
        GLRenderer(const GLRenderer&) = delete;

    };

}

#endif
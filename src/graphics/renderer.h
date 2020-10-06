#ifndef KOLLISION_RENDERER_H
#define KOLLISION_RENDERER_H

#pragma once

#include <clstl/vector.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "drawable.h"

namespace kollision {

    class Renderer {
    private:
        GLFWwindow* m_Window;
        int m_Width, m_Height;
        glm::mat4 m_MVP;
        clstl::vector<Drawable*> m_Drawables;
        
    public:
        explicit Renderer(GLFWwindow* window, int width, int height);

        void init();
        void addDrawable(Drawable* drawable);
        void renderFrame();

    };

}

#endif
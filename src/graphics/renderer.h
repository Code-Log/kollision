#ifndef KOLLISION_RENDERER_H
#define KOLLISION_RENDERER_H

#pragma once

#include <vector>
#include <GLFW/glfw3.h>
#include "drawable.h"

namespace kollision {

    class Renderer {
    private:
        std::vector<Drawable> drawables;
        
    public:
        Renderer(GLFWwindow* window);

        void init();
        void addDrawable(Drawable* drawable);
        void renderFrame();

    };

}

#endif
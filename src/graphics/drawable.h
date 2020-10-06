#ifndef KOLLISION_DRAWABLE_H
#define KOLLISION_DRAWABLE_H

#pragma once

#include <glm/glm.hpp>

namespace kollision {
    class Drawable {
    public:
        Drawable() = default;
        virtual void init() = 0;
        virtual void draw(const glm::mat4& mvp) = 0;
    };
}

#endif
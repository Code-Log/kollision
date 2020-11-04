#ifndef KOLLISION_DRAWABLE_H
#define KOLLISION_DRAWABLE_H

#pragma once

#include <glm/glm.hpp>

namespace kollision {
    class Drawable {
    public:
        virtual void init() = 0;
        virtual void draw(const glm::mat4&) = 0;
        virtual ~Drawable() = default;
        virtual void setPosition(const glm::vec2&) = 0;
    };
}

#endif
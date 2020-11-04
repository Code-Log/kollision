#ifndef KOLLISION_SHAPE_H
#define KOLLISION_SHAPE_H
#pragma once

#include <glm/glm.hpp>

namespace kollision {

    class Shape {

        virtual float& getMiddle() const = 0;
        virtual const glm::vec2& getPosition() const = 0;
        virtual void setPosition(const glm::vec2&) = 0;

    };

}

#endif //KOLLISION_SHAPE_H

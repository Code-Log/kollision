#ifndef KOLLISION_SHAPE_H
#define KOLLISION_SHAPE_H
#pragma once

#include <glm/glm.hpp>

namespace kollision {

    class Shape {

    public:
        virtual glm::vec2 getMiddle() const = 0;
        virtual const glm::vec2& getPosition() const = 0;
        virtual void setPosition(const glm::vec2&) = 0;
        virtual bool contains(const glm::vec2&) const = 0;
        virtual bool intersects(Shape*) const = 0;

    };

}

#endif //KOLLISION_SHAPE_H

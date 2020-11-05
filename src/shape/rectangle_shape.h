#ifndef KOLLISION_RECTANGLE_SHAPE_H
#define KOLLISION_RECTANGLE_SHAPE_H
#pragma once

#include "shape.h"

namespace kollision {
    class RectangleShape : public Shape {
    private:
        glm::vec2 m_Position;
        float m_Width, m_Height;

    public:

        RectangleShape() = default;
        RectangleShape(float m_Width, float m_Height, const glm::vec2& pos);

        auto getHeight() -> const float&;
        auto getWidth() -> const float&;

        glm::vec2 getMiddle() const override;

        const glm::vec2& getPosition() const override;
        void setPosition(const glm::vec2&) override;

        bool contains(const glm::vec2&) const override;
        bool intersects(Shape*) const override;

        void setWidth(const float& width);
        void setHeight(const float& height);

    };
}


#endif //KOLLISION_RECTANGLE_SHAPE_H

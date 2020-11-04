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
        RectangleShape(float m_Width, float m_Height);

        auto getHeight() -> const float&;
        auto getWidth() -> const float&;

        float& getMiddle() const override;

        const glm::vec2& getPosition() const override;
        void setPosition(const glm::vec2&) override;

        void setWidth(const float& width);
        void setHeight(const float& height);

    };
}


#endif //KOLLISION_RECTANGLE_SHAPE_H

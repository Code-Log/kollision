#include "rectangle_shape.h"

namespace kollision {

    auto RectangleShape::getHeight() -> const float& {
        return m_Height;
    }

    auto RectangleShape::getWidth() -> const float& {
        return m_Width;
    }

    void RectangleShape::setWidth(const float &width) { m_Width = width; }
    void RectangleShape::setHeight(const float &height) { m_Height = height; }

    RectangleShape::RectangleShape(float m_Width, float m_Height) : m_Width(m_Width), m_Height(m_Height) {

    }

}
#include "../../include/kollision/rectangle_shape.h"

namespace kollision {

    auto RectangleShape::getHeight() -> const float& {
        return m_Height;
    }

    auto RectangleShape::getWidth() -> const float& {
        return m_Width;
    }

    void RectangleShape::setWidth(const float &width) { m_Width = width; }
    void RectangleShape::setHeight(const float &height) { m_Height = height; }

    RectangleShape::RectangleShape(float m_Width, float m_Height, const glm::vec2& pos)
        : m_Width(m_Width), m_Height(m_Height), m_Position(pos)
    {

    }

    glm::vec2 RectangleShape::getMiddle() const {
        return glm::vec2(m_Position.x + m_Width / 2, m_Position.y + m_Height / 2);
    }

    const glm::vec2& RectangleShape::getPosition() const { return m_Position; }

    void RectangleShape::setPosition(const glm::vec2& pos) { m_Position = glm::vec2(pos); }

    bool RectangleShape::contains(const glm::vec2& pos) const {

        return !(pos.x < m_Position.x || pos.x > m_Position.x + m_Width)
            && !(pos.y < m_Position.y || pos.y > m_Position.y + m_Height);

    }

    bool RectangleShape::intersects(Shape* shape) const {

        if (RectangleShape* rect = dynamic_cast<RectangleShape*>(shape)) {

            if (rect->m_Position.x + rect->m_Width < m_Position.x)
                return false;
            if (rect->m_Position.x > m_Position.x + m_Width)
                return false;
            if (rect->m_Position.y + rect->m_Height < m_Position.y)
                return false;
            if (rect->m_Position.y > m_Position.y + m_Height)
                return false;

            return true;

        } else {
            return false;
        }

    }

}
#include "rigid_body.h"
#include "../shape/rectangle_shape.h"
#include "../graphics/opengl/GLRenderer.h"
#include "../graphics/opengl/GLRectangle.h"

namespace kollision {

    RigidBody::RigidBody(const Shape& hull)
        : m_Hull(hull), m_Position(glm::vec2(0)), m_Angle(0), m_Velocity(0), m_Acceleration(0), m_Mass(1)
    {

    }

    const glm::vec2 &RigidBody::getPosition() const { return m_Position; }
    void RigidBody::setPosition(const glm::vec2 &position) { m_Position = position; }

    float RigidBody::getAngle() const { return m_Angle; }
    void RigidBody::setAngle(float angle) { m_Angle = angle; }

    void RigidBody::setMass(const float &mass) { m_Mass = mass; }
    auto RigidBody::getMass() const -> const float & { return m_Mass; }

    RigidBody RigidBody::rectangleBody(float width, float height) {

        RigidBody body(RectangleShape(width, height));

        if (GLRenderer::ENABLE_RENDERER) {
            body.m_Drawable = new GLRectangle(width, height, body.m_Position);
            GLRenderer::get().addDrawable(body.m_Drawable);
        }

        return body;
    }

    RigidBody::~RigidBody() {
        if (m_Drawable) {
            GLRenderer::get().removeDrawable(m_Drawable);
            delete m_Drawable;
        }
    }

    void RigidBody::update() {

        force(m_Engine->m_Gravity * m_Mass);

        m_Velocity += m_Acceleration * m_Engine->m_dt;
        m_Position += m_Velocity * m_Engine->m_dt;

        m_Acceleration = glm::vec2(0.0f);

        m_Drawable->setPosition(m_Position);

    }

    void RigidBody::force(glm::vec2 F) {

        m_Acceleration += F / m_Mass;

    }

    void RigidBody::setEngine(Engine *engine) {
        m_Engine = engine;
    }

}
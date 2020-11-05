#ifndef KOLLISION_RIGID_BODY_H
#define KOLLISION_RIGID_BODY_H
#pragma once

#include <glm/glm.hpp>
#include "../shape/shape.h"
#include "engine.h"
#include "../graphics/drawable.h"

namespace kollision {

    class Engine;

    class RigidBody {
    private:
        glm::vec2 m_Position;
        glm::vec2 m_Velocity;
        glm::vec2 m_Acceleration;

        Engine* m_Engine;

        float m_Angle;
        float m_Mass;
        Shape* m_Hull;

        Drawable* m_Drawable;

    public:

        explicit RigidBody(Shape* hull);
        static RigidBody rectangleBody(float width, float height);

        void setMass(const float& mass);
        auto getMass() const -> const float&;

        void setEngine(Engine* engine);

        const glm::vec2& getPosition() const;

        void setPosition(const glm::vec2 &position);
        float getAngle() const;

        void setAngle(float angle);

        void update();

        void force(glm::vec2 F);

        ~RigidBody();

    };
}


#endif //KOLLISION_RIGID_BODY_H

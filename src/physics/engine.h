#ifndef KOLLISION_ENGINE_H
#define KOLLISION_ENGINE_H
#pragma once

#include <glm/glm.hpp>
#include <clstl/vector.h>
#include "rigid_body.h"

namespace kollision {

    class RigidBody;

    class Engine {

    private:
        glm::vec2 m_Gravity;
        float m_dt;
        clstl::vector<RigidBody*> m_Bodies;

    public:

        friend class RigidBody;

        explicit Engine(float dt);

        void addBody(RigidBody& body);

        void setGravity(glm::vec2 gravity);

        void step(unsigned int steps);
    };
}

#endif //KOLLISION_ENGINE_H

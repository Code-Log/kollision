#include "engine.h"

namespace kollision {

    Engine::Engine(float dt) : m_dt(dt), m_Gravity(0.0f, 9.8f) {

    }

    void Engine::step(unsigned int steps) {

        for (unsigned int i = 0; i < steps; i++) {
            for (unsigned int j = 0; j < m_Bodies.size(); j++) {
                m_Bodies[j]->update();
            }
        }

    }

    void Engine::addBody(RigidBody &body) {
        m_Bodies.push_back(&body);
        body.setEngine(this);
    }

    void Engine::setGravity(glm::vec2 gravity) {
        m_Gravity = gravity;
    }

}
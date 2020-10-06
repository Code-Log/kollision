#ifndef KOLLISION_RECTANGLE_H
#define KOLLISION_RECTANGLE_H

#pragma once

#include "drawable.h"
#include "shader.h"
#include "buffer.h"
#include <glm/glm.hpp>

namespace kollision {

    class Rectangle : public Drawable {
    private:
        glm::vec2 m_Position;
        double m_Width;
        double m_Height;

        Shader* m_Shader;
        Buffer* vbo;
        GLuint vao;

        
    public:
        Rectangle(double width, double height, double x, double y);
        Rectangle(double width, double height, glm::vec2 position);

        ~Rectangle();

        const glm::vec2& getPosition() const;
        void setPosition(const glm::vec2& position);

        const double& getHeight() const;
        const double& getWidth() const;

        void setHeight(const double& height);
        void setWidth(const double& width);

        void init() override;
        void draw(const glm::mat4& mvp) override;

    };
        
}

#endif
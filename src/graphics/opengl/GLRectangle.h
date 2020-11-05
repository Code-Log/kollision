#ifndef KOLLISION_GLRECTANGLE_H
#define KOLLISION_GLRECTANGLE_H

#pragma once

#include "../drawable.h"
#include "GLShader.h"
#include "GLBuffer.h"
#include <glm/glm.hpp>
#include "../Rectangle.h"

namespace kollision {

    class GLRectangle : public Rectangle {
    private:
        glm::vec2 m_Position;
        double m_Width;
        double m_Height;

        GLShader* m_Shader;
        GLBuffer* vbo;
        GLuint vao;

        
    public:
        GLRectangle(double width, double height, double x, double y);
        GLRectangle(double width, double height, glm::vec2 position);

        ~GLRectangle() override;

        glm::vec2& getPosition();
        void setPosition(const glm::vec2& position) override;

        const double& getHeight() const override;
        const double& getWidth() const override;

        void setHeight(const double& height) override;
        void setWidth(const double& width) override;

        void init() override;
        void draw(const glm::mat4& mvp) override;

    };
        
}

#endif
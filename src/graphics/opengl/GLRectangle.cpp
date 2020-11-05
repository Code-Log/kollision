#include "../../../include/kollision/GLRectangle.h"

namespace kollision {

    GLRectangle::GLRectangle(double width, double height, glm::vec2 position)
        : m_Width(width), m_Height(height), m_Position(glm::vec2(position)), m_Shader(nullptr), vbo(nullptr)
    {
        m_Shader = new GLShader("shaders/rect.vert.glsl", "shaders/rect.frag.glsl");
        vbo = new GLBuffer(GL_ARRAY_BUFFER);
    }

    GLRectangle::GLRectangle(double width, double height, double x, double y) :
            GLRectangle(width, height, glm::vec2(x, y)) { }

    GLRectangle::~GLRectangle() {
        delete m_Shader;
    }

    void GLRectangle::init() {

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        m_Shader->compile();

        auto* vertices = new float[12] {
                m_Position.x, m_Position.y, 0,
                m_Position.x + (float)m_Width, m_Position.y, 0,
                m_Position.x, m_Position.y + (float)m_Height, 0,
                m_Position.x + (float)m_Width, m_Position.y + (float)m_Height, 0,
        };

        vbo->bind();
        vbo->sendData<float>(vertices, 12);

        delete[] vertices;

    }

    void GLRectangle::draw(const glm::mat4& mvp) {

        glBindVertexArray(vao);

        auto* vertices = new float[12] {
                m_Position.x, m_Position.y, 0,
                m_Position.x + (float)m_Width, m_Position.y, 0,
                m_Position.x, m_Position.y + (float)m_Height, 0,
                m_Position.x + (float)m_Width, m_Position.y + (float)m_Height, 0,
        };

        vbo->bind();
        vbo->sendData<float>(vertices, 12);

        delete[] vertices;

        m_Shader->use();

        GLuint mvpLocation = glGetUniformLocation(m_Shader->id, "mvp");
        glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvp[0][0]);

        glEnableVertexAttribArray(0);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glDisableVertexAttribArray(0);

    }

    glm::vec2& GLRectangle::getPosition() { return m_Position; }
    void GLRectangle::setPosition(const glm::vec2& position) { m_Position = position; }

    const double& GLRectangle::getWidth() const { return m_Width; }
    const double& GLRectangle::getHeight() const { return m_Height; }

    void GLRectangle::setWidth(const double& width) { m_Width = width; }
    void GLRectangle::setHeight(const double& height) { m_Height = height; }

}

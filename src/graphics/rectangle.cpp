#include "rectangle.h"

namespace kollision {

    struct Vertex {
        float x, y, r, g, b, a;
    };

    Rectangle::Rectangle(double width, double height, glm::vec2 position)
        : m_Width(width), m_Height(height), m_Position(position), m_Shader(nullptr), vbo(nullptr)
    {
        m_Shader = new Shader("shaders/rect.vert.glsl", "shaders/rect.frag.glsl");
        vbo = new Buffer(GL_ARRAY_BUFFER);
    }

    Rectangle::Rectangle(double width, double height, double x, double y) :
        Rectangle(width, height, glm::vec2(x, y)) { }

    Rectangle::~Rectangle() {
        delete m_Shader;
    }

    void Rectangle::init() {

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        m_Shader->compile();

        float vertices[4 * 6] = {
                m_Position.x, m_Position.y, 1, 1, 1, 1,
                m_Position.x + (float)m_Width, m_Position.y, 1, 1, 1, 1,
                m_Position.x, m_Position.y + (float)m_Height, 1, 1, 1, 1,
                m_Position.x + (float)m_Width, m_Position.y + (float)m_Height, 1, 1, 1, 1,
        };

        vbo->sendData(vertices, 4);

    }

    void Rectangle::draw(const glm::mat4& mvp) {

        glBindVertexArray(vao);
        m_Shader->use();
        vbo->bind();

        GLuint mvpLocation = glGetUniformLocation(m_Shader->id, "mvp");
        glUniformMatrix4fv(mvpLocation, 1, false, &mvp[0][0]);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

    }

    const glm::vec2& Rectangle::getPosition() const { return m_Position; }
    void Rectangle::setPosition(const glm::vec2& position) { m_Position = position; }

    const double& Rectangle::getWidth() const { return m_Width; }
    const double& Rectangle::getHeight() const { return m_Height; }

    void Rectangle::setWidth(const double& width) { m_Width = width; }
    void Rectangle::setHeight(const double& height) { m_Height = height; }

}

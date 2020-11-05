#include "../../../include/kollision/GLBuffer.h"

namespace kollision {

    GLBuffer::GLBuffer(GLuint type) : type(type), id(0) {
        glCreateBuffers(1, &id);
    }

    void GLBuffer::bind() const { glBindBuffer(type, id); }

    GLBuffer::~GLBuffer() { glDeleteBuffers(1, &id); }
}
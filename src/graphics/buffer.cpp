#include "buffer.h"

namespace kollision {

    Buffer::Buffer(GLuint type) : type(type), id(0) {
        glCreateBuffers(1, &id);
    }

    void Buffer::bind() const { glBindBuffer(type, id); }

    Buffer::~Buffer() { glDeleteBuffers(1, &id); }
}
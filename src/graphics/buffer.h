#ifndef KOLLISION_BUFFER_H
#define KOLLISION_BUFFER_H

#pragma once

#include <GL/glew.h>
#include <GL/gl.h>

namespace kollision {
    struct Buffer {

        GLuint id;
        GLuint type;

        explicit Buffer(GLuint type);
        ~Buffer();

        template<typename T>
        void sendData(T* data, unsigned int n) {
            bind();
            glBufferData(type, n * sizeof(T), data, GL_STATIC_DRAW);
        }

        void bind() const;

    };
}


#endif //KOLLISION_BUFFER_H

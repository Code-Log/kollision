#ifndef KOLLISION_GLBUFFER_H
#define KOLLISION_GLBUFFER_H

#pragma once

#include <GL/glew.h>
#include <GL/gl.h>

namespace kollision {
    struct GLBuffer {

        GLuint id;
        GLuint type;

        explicit GLBuffer(GLuint type);
        ~GLBuffer();

        template<typename T>
        void sendData(T* data, unsigned int n) {
            bind();
            glBufferData(type, n * sizeof(T), data, GL_STATIC_DRAW);
        }

        void bind() const;

    };
}


#endif //KOLLISION_GLBUFFER_H

#ifndef KOLLISION_GLSHADER_H
#define KOLLISION_GLSHADER_H

#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <clstl/string.h>

namespace kollision {

    struct GLShader {

        GLuint id;
        std::string vertexSource;
        std::string fragmentSource;

        GLShader(const std::string& vertexPath, const std::string& fragmentPath);
        ~GLShader();

        void compile();
        void use() const;

        struct shader_compile_exception : public std::exception {
            const char* msg;
            explicit shader_compile_exception(const char* msg) : msg(msg) {}
            const char* what() const noexcept override {
                return msg;
            }
        };

    };

}

#endif
#include "../../../include/kollision/GLShader.h"
#include "../../../include/kollision/util.h"
#include <fstream>
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <memory>

namespace kollision {

    GLShader::GLShader(const std::string& vertexPath, const std::string& fragmentPath) {

        id = glCreateProgram();

        vertexSource = readFile(vertexPath).value_or("");
        fragmentSource = readFile(fragmentPath).value_or("");

    }

    void checkShaderCompile(GLuint shader, GLuint type) {

        GLint status = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

        if (status != GL_TRUE) {

            GLint logLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
            auto log = (GLchar*)alloca(logLength);
            glGetShaderInfoLog(shader, logLength, nullptr, log);

            throw GLShader::shader_compile_exception(log);

        }

    }

    GLShader::~GLShader() {
    }

    void GLShader::use() const { glUseProgram(id); }

    void GLShader::compile() {

        GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
        GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);

        const char* vss = vertexSource.c_str();
        const char* fss = fragmentSource.c_str();
        glShaderSource(vshader, 1, &vss, nullptr);
        glShaderSource(fshader, 1, &fss, nullptr);

        glCompileShader(vshader);
        checkShaderCompile(vshader, GL_VERTEX_SHADER);

        glCompileShader(fshader);
        checkShaderCompile(fshader, GL_FRAGMENT_SHADER);

        glAttachShader(id, vshader);
        glAttachShader(id, fshader);

        glLinkProgram(id);

        GLint val;
        glGetProgramiv(id, GL_LINK_STATUS, &val);
        if (val != GL_TRUE)
            throw shader_compile_exception("Couldn't link shader!");

        glDeleteShader(vshader);
        glDeleteShader(fshader);

    }

}
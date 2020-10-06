#version 330 core

layout(location = 0) in vec2 vertPos;
layout(location = 1) in vec4 vertColor;

out vec4 color;
uniform mat4 mvp;

void main() {

    gl_Position = vec4(vertPos, 0, 1);
    color = vertColor;

}

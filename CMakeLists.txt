cmake_minimum_required(VERSION 3.12)
project(kollision)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(physics src/main.cpp
        src/graphics/shader.cpp
        src/graphics/rectangle.cpp
        src/graphics/buffer.cpp
        src/graphics/DrawableContext.cpp
)

set_target_properties(physics PROPERTIES CXX_STANDARD 17)

target_link_libraries(physics GLEW)
target_link_libraries(physics glfw)
target_link_libraries(physics GL)

configure_file(src/shaders/rect.vert.glsl shaders/rect.vert.glsl COPYONLY)
configure_file(src/shaders/rect.frag.glsl shaders/rect.frag.glsl COPYONLY)
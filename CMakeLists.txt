cmake_minimum_required(VERSION 3.12)
project(kollision)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_library(kollision
        src/graphics/opengl/GLShader.cpp
        include/kollision/GLShader.h
        src/graphics/opengl/GLRectangle.cpp
        include/kollision/GLRectangle.h
        include/kollision/GLBuffer.h
        src/graphics/opengl/GLBuffer.cpp
        include/kollision/GLRenderer.h
        src/graphics/opengl/GLRenderer.cpp
        include/kollision/engine.h
        src/physics/engine.cpp
        include/kollision/rigid_body.h
        src/physics/rigid_body.cpp
        include/kollision/rectangle_shape.h
        src/shape/rectangle_shape.cpp
        include/kollision/Renderer.h
        src/graphics/Renderer.cpp
        include/kollision/Rectangle.h
        include/kollision/quad_tree.h
        src/util/quad_tree.cpp
)

add_executable(physics_test src/main.cpp)

set_target_properties(physics_test PROPERTIES CXX_STANDARD 17)
set_target_properties(kollision PROPERTIES CXX_STANDARD 17)

target_link_libraries(kollision GLEW)
target_link_libraries(kollision glfw)
target_link_libraries(kollision GL)
target_link_libraries(kollision clstl)
target_link_libraries(kollision GL)

target_link_libraries(physics_test GLEW)
target_link_libraries(physics_test glfw)
target_link_libraries(physics_test GL)
target_link_libraries(physics_test clstl)
target_link_libraries(physics_test kollision)

configure_file(src/shaders/rect.vert.glsl shaders/rect.vert.glsl COPYONLY)
configure_file(src/shaders/rect.frag.glsl shaders/rect.frag.glsl COPYONLY)
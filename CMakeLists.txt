cmake_minimum_required(VERSION 3.12)
project(kollision)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_library(kollision
        src/graphics/opengl/GLShader.cpp
        src/graphics/opengl/GLShader.h
        src/graphics/opengl/GLRectangle.cpp
        src/graphics/opengl/GLRectangle.h
        src/graphics/opengl/GLBuffer.h
        src/graphics/opengl/GLBuffer.cpp
        src/graphics/opengl/GLRenderer.h
        src/graphics/opengl/GLRenderer.cpp
        src/physics/engine.h
        src/physics/engine.cpp
        src/physics/rigid_body.h
        src/physics/rigid_body.cpp
        src/shape/rectangle_shape.h
        src/shape/rectangle_shape.cpp
        src/util/positioned.h src/graphics/Renderer.h src/graphics/Renderer.cpp src/graphics/Rectangle.h)

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
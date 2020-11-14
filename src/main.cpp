#include <exception>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <kollision/GLRenderer.h>
#include <kollision/rigid_body.h>

using namespace kollision;

class MainListener : public RenderListener {
private:
    Renderer* renderer;
    Engine engine;
    RigidBody body;

public:

    explicit MainListener(GLRenderer* renderer) : renderer(renderer),
                                                  body(RigidBody::rectangleBody(200, 100)), engine(1) {}

    void setup() override {
        body.setMass(0.05f);
        body.setPosition(glm::vec2(400, 0));
        engine.setGravity(glm::vec2(0.0f, 1.0f));
        engine.addBody(body);
    }

    void draw() override {
        engine.step(1);
    }

    ~MainListener() {
    }

};

auto main() -> int {

    glewExperimental = true;

    if (!glfwInit()) {
        std::cerr << "Couldn't initialize GLFW!" << std::endl;
        throw std::exception();
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto* window = glfwCreateWindow(800, 600, "Physics", nullptr, nullptr);

    GLRenderer::WINDOW = window;
    GLRenderer& renderer = GLRenderer::get();
    renderer.init();

    auto* mainListener = new MainListener(&renderer);
    mainListener->setup();
    renderer.addRenderListener(mainListener);

    renderer.start();

    delete mainListener;

    glfwDestroyWindow(window);
    glfwTerminate();

}
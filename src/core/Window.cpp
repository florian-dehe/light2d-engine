#include "Window.h"

#include <stdexcept>

#include "../third_party/stb/stb_image.h"

#include "Logger.h"

#include "../input/InputManager.h"

#include "../third_party/imgui/imgui.h"
#include "../third_party/imgui/imgui_impl_glfw.h"
#include "../third_party/imgui/imgui_impl_opengl3.h"

using namespace light2d::core;

Window::Window(std::string title, int width, int height) {
    this->title = title;
    this->width = width;
    this->height = height;
}

Window::~Window() {
}

void Window::init() {
    if (!glfwInit()) {
        throw std::runtime_error("ERROR :: GLFW :: Failed to initialize GLFW !");
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4); // Anti-aliasing
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    win = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    
    if (!win) {
        const char* err = " ";
#if GLFW_VERSION_MAJOR >= 3
    #if GLFW_VERSION_MINOR >= 3
        glfwGetError(&err);
    #endif
#endif
        glfwTerminate();
        throw std::runtime_error("ERROR :: GLFW :: Failed to create window !" + std::string(err));
    }
    
    glfwMakeContextCurrent(win);
    
    //Set Callbacks
    glfwSetFramebufferSizeCallback(win, framebufferSizeCallback);
    
    glfwSetKeyCallback(win, input::InputManager::keyCallback);
    glfwSetCursorPosCallback(win, input::InputManager::cursorPositionCallback);
    glfwSetMouseButtonCallback(win, input::InputManager::mouseButtonCallback);
    glfwSetScrollCallback(win, input::InputManager::mouseScrollCallback);
    
    glfwSetWindowAspectRatio(win, width, height);
    this->setIcon("res/built-in/textures/logo.png");
    
    /**
     * Glew loader init.
     */
    glewExperimental = GL_TRUE; // OpenGL Core profile
    glewInit();
    
    Logger::get()->info("Light2D Engine : OpenGL configuration", "OpenGL vendor : " + std::string((char*)glGetString(GL_VENDOR)));
    Logger::get()->info("Light2D Engine : OpenGL configuration", "OpenGL renderer : " + std::string((char*)glGetString(GL_RENDERER)));
    Logger::get()->info("Light2D Engine : OpenGL configuration", "OpenGL version : " + std::string((char*)glGetString(GL_VERSION)));
    Logger::get()->info("Light2D Engine : OpenGL configuration", "OpenGL shading language version : " + std::string((char*)glGetString(GL_SHADING_LANGUAGE_VERSION)));

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(Logger::GLErrorCallback, 0);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGui::StyleColorsDark();
    
    ImGui_ImplGlfw_InitForOpenGL(win, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}

void Window::destroy() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    glfwDestroyWindow(win);
    glfwTerminate();
}

void Window::beginFrame() {
    startFrameTime = glfwGetTime();
    
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Window::endFrame() {
    ImGui::Render();
    
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    glfwSwapBuffers(win);
    
    windowShouldClose = glfwWindowShouldClose(win);
    endFrameTime = glfwGetTime();
    delta = endFrameTime - startFrameTime;
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int Window::getWidth() {
    glfwGetFramebufferSize(win, &width, NULL);
    return this->width;
}

int Window::getHeight() {
    glfwGetFramebufferSize(win, NULL, &height);
    return this->height;
}

void Window::setIcon(std::string filepath) {
    stbi_set_flip_vertically_on_load(false);
    
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);
    
    if (data != nullptr) {
        GLFWimage image;
        image.width = height;
        image.height = height;
        image.pixels = data;
        glfwSetWindowIcon(win, 1, &image);
    }
}
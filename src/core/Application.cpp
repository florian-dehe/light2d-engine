#include "Application.h"

#include <chrono>

#include "../input/Input.h"
#include "../rendering/Renderer.h"
#include "../audio/Audio.h"

using namespace light2d::core;
using namespace light2d::objects;

Application::Application(std::string title, int width, int height) {
    window = new Window(title, width, height);
}

Application::~Application() {
    delete window;
}

void Application::init() {
    window->init();
    rendering::Renderer::init(window->getWidth(), window->getHeight());
    audio::Audio::init();
    onInit();
}

void Application::destroy() {
    currentScene->onDestroy();
    
    onDestroy();
    audio::Audio::deinit();
    window->destroy();
}

void Application::run(objects::Scene* startScene) {
    if (startScene == nullptr)
        return;
    
    currentScene = startScene;
    currentScene->onInit();
    while (isRunning) {
        window->beginFrame();
        isRunning = !window->shouldClose();
        
        currentScene->onRender();
        onRender();
        currentScene->onUpdate(window->getDelta());
        onUpdate(window->getDelta());
        
        input::Input::getEventQueue()->clear();
        window->endFrame();
    }
}

void Application::quit() {
    isRunning = false;
}

int Application::getWindowWidth() {
    return this->window->getWidth();
}

int Application::getWindowHeight() {
    return this->window->getHeight();
}

void Application::setWindowIcon(std::string filepath) {
    this->window->setIcon(filepath);
}

Scene* Application::changeSceneTo(Scene* newScene) {
    if (newScene == nullptr)
        return nullptr;
    
    currentScene->onDestroy();
    Scene* tmp = currentScene;
    currentScene = newScene;
    currentScene->onInit();
    
    return tmp;
}

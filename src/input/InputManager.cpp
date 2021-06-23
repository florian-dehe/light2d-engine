#include "InputManager.h"

#include "../core/Logger.h"

#include "Event.h"
#include "EventQueue.h"
#include "Input.h"

using namespace light2d::input;

bool InputManager::logEvents = false;

void InputManager::keyCallback(GLFWwindow* win, int key, int scancode, int action, int mods) {
    KeyboardEvent* evt = new KeyboardEvent();
    
    const char* keyName = glfwGetKeyName(key, 0);
        
    if (keyName != NULL)
        evt->name = std::string(keyName);
    else
        evt->name = "Key : " + std::to_string(key);

    evt->type = EventType::KEYBOARD;
    
    evt->key = key;
    evt->scancode = scancode;
    evt->action = action;
    evt->mods = mods;
    
    Input::getEventQueue()->pushBack(evt);
        
    if (logEvents)
        core::Logger::get()->info("Event", std::string(evt->name));
}

void InputManager::cursorPositionCallback(GLFWwindow* win, double xpos, double ypos) {
    MousePosition mousePosition;
    
    mousePosition.before_x = mousePosition.x;
    mousePosition.before_y = mousePosition.y;
    
    mousePosition.x = xpos;
    mousePosition.y = ypos;
    
    Input::mousePosition = mousePosition;
    
    if (logEvents)
        core::Logger::get()->info("Event", "Mouse Position : " + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y));
}

void InputManager::mouseButtonCallback(GLFWwindow* win, int button, int action, int mods) {
    MouseButtonEvent evt;
    
    evt.name = "Mouse Button " + std::to_string(button);
    evt.type = EventType::MOUSE_BUTTON;
    
    evt.button = button;
    evt.action = action;
    evt.mods = mods;
    
    Input::getEventQueue()->pushBack(new MouseButtonEvent(evt));
    
    if (logEvents)
        core::Logger::get()->info("Event", std::string(evt.name));
}
void InputManager::mouseScrollCallback(GLFWwindow* win, double xoffset, double yoffset) {
    MouseScrollEvent evt;
    
    evt.name = "Mouse Scroll";
    evt.type = EventType::MOUSE_SCROLL;
    
    evt.xoffset = xoffset;
    evt.yoffset = yoffset;
    
    Input::getEventQueue()->pushBack(new MouseScrollEvent(evt));
    
    if (logEvents)
        core::Logger::get()->info("Event", "Mouse Scroll : " + std::to_string(xoffset) + "," + std::to_string(yoffset));
}

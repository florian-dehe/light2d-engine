#include "Input.h"

using namespace light2d::input;

MousePosition Input::mousePosition;
EventQueue* Input::eventQueue = new EventQueue();

MousePosition Input::getMousePosition() {
    return mousePosition;
}

EventQueue* Input::getEventQueue() {
    return eventQueue;
}

bool Input::isKeyPressed(int keycode) {
    auto keys = eventQueue->getKeyPressed();
    return keys.find(keycode) != keys.end();
}

bool Input::isKeyJustPressed(int keycode) {
    auto keys = eventQueue->getKeyJustPressed();
    return keys.find(keycode) != keys.end();
}

bool Input::isKeyJustReleased(int keycode) {
    auto keys = eventQueue->getKeyJustReleased();
    return keys.find(keycode) != keys.end();
}
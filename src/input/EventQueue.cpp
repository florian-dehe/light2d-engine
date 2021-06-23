#include "EventQueue.h"

using namespace light2d::input;

EventQueue::EventQueue() {
    queue = std::queue<Event*>();
    keyPressed = std::set<int>();
    keyJustPressed = std::set<int>();
    keyJustReleased = std::set<int>();
}

EventQueue::~EventQueue() {
    clear();
}

Event* EventQueue::poll() {
    if (polled) {
        queue.pop();
    }
    else {
        polled = true;
    }
    return queue.front();
}

void EventQueue::pushBack(Event* evt) {
    queue.push(evt);
    if (evt->type == EventType::KEYBOARD) {
        KeyboardEvent* kbEvt = (KeyboardEvent*)evt;
        if (kbEvt->action == (int)EventAction::PRESS) {
            keyJustPressed.insert(kbEvt->key);
            keyPressed.insert(kbEvt->key);
        }
        else if (kbEvt->action == (int)EventAction::RELEASE) {
            keyPressed.erase(kbEvt->key);
            keyJustReleased.insert(kbEvt->key);
        }
    }
}

void EventQueue::clear() {
    for (int i = 0; i < queue.size(); i++) {
        delete queue.front();
        queue.pop();
    }
    
    keyJustPressed.clear();
    keyJustReleased.clear();
    
    polled = false;
}

bool EventQueue::empty() {
    return (queue.size() == 1) && polled || queue.size() == 0;
}

#include "GameObjectGroup.h"

using namespace light2d::objects;


void GameObjectGroup::init() {
    for (auto & gameObject : gameObjects) {
        gameObject->init();
    }
}

void GameObjectGroup::update() {
    for (auto & gameObject : gameObjects) {
        gameObject->update();
    }
}

void GameObjectGroup::render() {
    for (auto & gameObject : gameObjects) {
        gameObject->render();
    }
}

void GameObjectGroup::destroy() {
    for (auto & gameObject : gameObjects) {
        gameObject->destroy();
    }
}


void GameObjectGroup::addObject(light2d::objects::GameObject* gameObject) {
    if (!isInGroup(gameObject))
        gameObjects.push_back(gameObject);
}

void GameObjectGroup::removeObject(light2d::objects::GameObject* gameObject) {
    if (isInGroup(gameObject))
        gameObjects.erase(findIterator(gameObject));
}


bool GameObjectGroup::isInGroup(GameObject* gameObject) {
    auto it = gameObjects.begin();
    bool found = false;
    while (!found && it != gameObjects.end()) {
        found = *it == gameObject;
        it++;
    }
    return found;
}

std::vector<GameObject *>::iterator GameObjectGroup::findIterator(GameObject *gameObject) {
    auto it = gameObjects.begin();

    while (*it != gameObject || it != gameObjects.end())
        it++;

    return it;
}

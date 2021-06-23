#include "Transform.h"

#include <glm/ext/matrix_transform.hpp>

using namespace light2d::rendering;

Transform::Transform() {
}

Transform::~Transform() {
}

void Transform::reset() {
    this->model = glm::mat4(1.0f);
    
    this->position = glm::vec2(0.f);
    this->rotationDegrees = 0.f;
    this->scaleVector = glm::vec2(1.f);
}

void Transform::move(glm::vec2 moveVector) {
    position += moveVector;
    applyTransform();
}

void Transform::setPosition(glm::vec2 position) {
    applyTransform(position, this->rotationDegrees, this->scaleVector);
}

void Transform::rotate(float degrees) {
    rotationDegrees += degrees;
    applyTransform();
}

void Transform::setRotation(float degrees) {
    applyTransform(this->position, degrees, this->scaleVector);
}

void Transform::scale(glm::vec2 scaleVector) {
    this->scaleVector.x *= scaleVector.x;
    this->scaleVector.y *= scaleVector.y;
    applyTransform();
}

void Transform::setScale(glm::vec2 scaleVector) {
    applyTransform(this->position, this->rotationDegrees, scaleVector);
}

void Transform::applyTransform(glm::vec2 pos, float degrees, glm::vec2 scaleVector) {
    reset();
    
    this->position = pos;
    this->rotationDegrees = degrees;
    this->scaleVector = scaleVector;
    
    model = glm::translate(model, glm::vec3(pos, 0.f));
    model = glm::rotate(model, glm::radians(degrees), glm::vec3(0.f, 0.f, -1.f));
    model = glm::scale(model, glm::vec3(scaleVector, 1.f));
}

void Transform::applyTransform() {
    applyTransform(this->position, this->rotationDegrees, this->scaleVector); 
}


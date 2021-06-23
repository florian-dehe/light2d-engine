#include "Camera.h"

#include <glm/ext/matrix_transform.hpp>

using namespace light2d::rendering;

Camera::Camera() {
}

Camera::~Camera() {
}

void Camera::move(glm::vec2 move) {
    pos += move;
    applyTransform();
}

void Camera::setPosition(glm::vec2 pos) {
    this->pos = pos;
    applyTransform();
}
            
void Camera::zoom(float zoom) {
    zoomFactor *= zoom;
    applyTransform();
}

void Camera::setZoom(float zoom) {
    zoomFactor = zoom;
    applyTransform();
}
            
void Camera::reset() {
    view = glm::mat4(1.f); // Identity.
    zoomFactor = 1.f;
    pos = glm::vec2(0.f);
}

void Camera::applyTransform() {
    view = glm::mat4(1.f);
    
    view = glm::scale(view, glm::vec3(zoomFactor, zoomFactor, 1.f));
    view = glm::translate(view, glm::vec3(pos, 0.f));
    
}
#include "Viewport.h"

#include <glm/ext/matrix_clip_space.hpp>

using namespace light2d::rendering;

Viewport::Viewport(int width, int height) {
    this->width = width;
    this->height = height;
    
    resize(width, height);
}

Viewport::~Viewport() {
}

void Viewport::resize(int width, int height) {
    this->width = width;
    this->height = height;
    
    float left = 0.f;
    float right = width;
    float top = 0.f;
    float bottom = height;
    
    projection = glm::ortho(left, right, top, bottom, -100.f, 100.f);
}
#include "VertexBuffer.h"

#include <GL/glew.h>
#include <string>

#include "../core/Logger.h"

using namespace light2d::core_graphics;

VertexBuffer::VertexBuffer() {
    
}

VertexBuffer::~VertexBuffer() {
}

void VertexBuffer::create(uint32_t data_size, const void* data) {    
    glGenBuffers(1, &this->buffer_id);
        
    bind();
    glBufferData(GL_ARRAY_BUFFER, data_size, data, GL_STATIC_DRAW);
    unbind();
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer_id);
}

void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::destroy() {
    glDeleteBuffers(1, &this->buffer_id);
}

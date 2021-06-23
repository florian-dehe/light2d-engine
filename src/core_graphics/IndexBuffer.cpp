#include "IndexBuffer.h"

#include <GL/glew.h>

using namespace light2d::core_graphics;

IndexBuffer::IndexBuffer() {
}

IndexBuffer::~IndexBuffer() {
}

void IndexBuffer::create(uint32_t data_count, const void* data) {
    this->indexCount = data_count;    
    
    glGenBuffers(1, &this->buffer_id);
        
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data_count*sizeof(uint32_t), data, GL_STATIC_DRAW);
    unbind();
}

void IndexBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->buffer_id);
}

void IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::destroy() {
    glDeleteBuffers(1, &this->buffer_id);
}


#include "VertexArray.h"

#include <GL/glew.h>

#include <string>

#include "../core/Logger.h"

using namespace light2d::core_graphics;

VertexArray::VertexArray(VertexBufferLayout layout) {
    this->layout = layout;
}

VertexArray::~VertexArray() {
    
}

void VertexArray::create() {
    glGenVertexArrays(1, &object_id);
}

void VertexArray::bind() {
    glBindVertexArray(object_id);
    
    this->vertexBuffer->bind();
    
    if (this->indexBuffer != nullptr)
        this->indexBuffer->bind();
}

void VertexArray::unbind() {
    if (this->indexBuffer != nullptr)
        this->indexBuffer->unbind();
    
    this->vertexBuffer->unbind();
    glBindVertexArray(0);
}
void VertexArray::destroy() {
    glDeleteVertexArrays(1, &object_id);
}

void VertexArray::setVertexBuffer(VertexBuffer* vertexBuffer) {
    this->vertexBuffer = vertexBuffer;
    
    std::vector<VertexBufferAttribute> attributes = layout.getAttributes();
    
    bind();
    
    vertexBuffer->bind();
    
    for (int i = 0; i < attributes.size(); i++) {
        
        glVertexAttribPointer(i,    attributes[i].size,
                                    VertexBufferLayout::attributeTypeToGLenum(attributes[i].type),
                                    attributes[i].normalized, layout.getStride(),(void*)attributes[i].offset);
        
        glEnableVertexAttribArray(i);
    }

    unbind();
}

void VertexArray::setIndexBuffer(IndexBuffer* indexBuffer) {
    this->indexBuffer = indexBuffer;
}
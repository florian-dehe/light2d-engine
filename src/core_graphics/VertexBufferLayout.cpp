#include "VertexBufferLayout.h"

using namespace light2d::core_graphics;

VertexBufferLayout::VertexBufferLayout() {
    this->attributes = std::vector<VertexBufferAttribute>();
}

VertexBufferLayout::~VertexBufferLayout() {
    attributes.clear();
}

void VertexBufferLayout::addAttribute(VertexBufferAttributeType type, uint32_t size, bool normalized) {
    VertexBufferAttribute attr;
    attr.type = type;
    attr.size = size;
    attr.normalized = normalized;
    attr.offset = stride;
    
    attributes.push_back(attr);
    
    switch(type) {
        case Float : stride += size * sizeof(float); break;
        case Int : stride += size * sizeof(int); break;
        case Bool : stride += size * sizeof(bool); break;
    }
    
    layoutSize += size;
}

GLenum VertexBufferLayout::attributeTypeToGLenum(VertexBufferAttributeType type) {
    switch (type) {
        case Float : return GL_FLOAT;
        case Int : return GL_INT;
        case Bool : return GL_BOOL;
    }
    
    return 0;
}
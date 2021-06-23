#include "Mesh.h"

#include <string>

#include "../core/Logger.h"

using namespace light2d::rendering;

Mesh::Mesh() {
}

Mesh::~Mesh() {
}

void Mesh::setData(std::vector<float> vertices, bool indexed, std::vector<uint32_t> indices, core_graphics::VertexBufferLayout layout) {
    vao = new core_graphics::VertexArray(layout);
    vao->create();
    
    
    this->indexed = indexed;
    if (indexed) {
        ebo = new core_graphics::IndexBuffer();
        ebo->create(indices.size(), indices.data());
        vao->setIndexBuffer(ebo);
    }
    
    vbo = new core_graphics::VertexBuffer();
    vbo->create(vertices.size() * sizeof(float), vertices.data());
    
    this->vertexCount = vertices.size() / layout.getLayoutSize();
    
    vao->setVertexBuffer(vbo);
}

void Mesh::bind() {
    vao->bind();
}

void Mesh::unbind() {
    vao->unbind();
}

uint32_t Mesh::getIndexCount() {
    return vao->getIndexCount();
}

uint32_t Mesh::getVertexCount() {
    return this->vertexCount;
}

void Mesh::destroy() {
    vbo->destroy();
    if (indexed)
        ebo->destroy();
    
    vao->destroy();
}



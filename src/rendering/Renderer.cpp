#include "Renderer.h"

#include <glm/gtc/type_ptr.hpp>

using namespace light2d::rendering;

bool Renderer::initialized = false;
Viewport* Renderer::viewport = nullptr;
Camera* Renderer::currentCamera = nullptr;

void Renderer::init(int width, int height) {
    viewport = new Viewport(width, height);
    currentCamera = new Camera();
    
    initialized = true;
}

void Renderer::drawMesh(Mesh* mesh, Transform& transform, Material* material) {
    material->bind();
    
    core_graphics::Shader* shader = material->getShader();
    shader->setMatrix4("u_proj", false, glm::value_ptr(viewport->getProjectionMatrix()));
    shader->setMatrix4("u_view", false, glm::value_ptr(currentCamera->getViewMatrix()));
    shader->setMatrix4("u_model", false, glm::value_ptr(transform.getModelMatrix()));
    
    mesh->bind();
    
    if (mesh->isIndexed())
        glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, (void*)0);
    else
        glDrawArrays(GL_TRIANGLES, 0, mesh->getVertexCount());
    
    mesh->unbind();
    
    material->unbind();
}


void Renderer::resizeViewport(int width, int height) {
    if (initialized)
        viewport->resize(width, height);
}

int Renderer::getViewportWidth() {
    if (initialized)
        return viewport->getWidth();
    return 0;
}

int Renderer::getViewportHeight() {
    if (initialized)
        return viewport->getHeight();
    return 0;
}

Camera* Renderer::getCurrentCamera() {
    return currentCamera;
}

void Renderer::setCurrentCamera(Camera* camera) {
    currentCamera = camera;
}
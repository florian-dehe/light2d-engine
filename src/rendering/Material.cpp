#include "Material.h"

#include <glm/gtc/type_ptr.hpp>

#include "../core/Logger.h"

using namespace light2d::rendering;

void Material::setShader(core_graphics::Shader* shader) {
    this->shader = shader;
}

void Material::bind() {
    if (shader == nullptr) {
        core::Logger::get()->error("Material", "No shader assiocated to this material !");
        return;
    }
    
    
    this->shader->bind();
    
    for (int i = 0; i < textures.size(); i++) {
        if (textures[i] == nullptr)
            continue;
        
        this->shader->setInt("u_Texture_" + std::to_string(i), i);
        textures[i]->bind(i);
    }
    
    for (int i = 0; i < colors.size(); i++) {
        glm::vec4 color = colors[i];
        this->shader->setFloat4("u_Color_" + std::to_string(i), glm::value_ptr(color));
    }
}

void Material::unbind() {
    for (int i = 0; i < textures.size(); i++) {
        textures[i]->unbind();
    }
    
    this->shader->unbind();
}
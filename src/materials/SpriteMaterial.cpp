#include "SpriteMaterial.h"

using namespace light2d::materials;

using namespace light2d::core_graphics;

SpriteMaterial::SpriteMaterial() {
    this->setShader(this->spriteShader);
    this->getTextures()->push_back(mainTexture);
    this->getColors()->push_back(mainColor);
}

SpriteMaterial::~SpriteMaterial() {
}

void SpriteMaterial::init() {
    this->spriteShader->create( "res/built-in/shaders/sprite.vert.glsl",
                                "res/built-in/shaders/sprite.frag.glsl");
}

void SpriteMaterial::destroy() {
    this->spriteShader->destroy();
}

void SpriteMaterial::setMainColor(glm::vec4 mainColor) {
    this->mainColor = mainColor;
    
    auto colors = this->getColors();
    colors->at(0) = mainColor;
}

Texture* SpriteMaterial::setMainTexture(Texture* mainTexture) {
    this->mainTexture = mainTexture;
    
    auto textures = this->getTextures();
    
    auto old_tex = textures->at(0);
    
    textures->at(0) = mainTexture;
    
    return old_tex;
}


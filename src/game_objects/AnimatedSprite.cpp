#include "AnimatedSprite.h"

using namespace light2d::objects;

AnimatedSprite::AnimatedSprite(std::vector<std::string> filePaths, core_graphics::TextureConfig config, float fps) 
    : Sprite(config) {
    this->filePaths = filePaths;
    this->config = config;
    this->fps = fps;
}

AnimatedSprite::~AnimatedSprite() {
}

void AnimatedSprite::init() {
    this->Sprite::init();
    init_textures();
}

void AnimatedSprite::init(materials::SpriteMaterial* spriteMaterial) {
    this->Sprite::init(spriteMaterial);
    init_textures();
}

void AnimatedSprite::update(double delta) {
    currentTime += delta;
    if (currentTime > 1.0/fps) {
        currentTime = 0.0;
        swap_texture();
    }
}

void AnimatedSprite::init_textures() {
    textures = std::vector<core_graphics::Texture*>();
    
    for (int i=0; i < filePaths.size(); i++) {
        core_graphics::Texture* tex = new core_graphics::Texture();
        tex->create(filePaths.at(i), config);
        textures.push_back(tex);
    }
    
    this->setMainTexture(textures.at(0), true);
}

void AnimatedSprite::swap_texture() {
    textureIndex++;
    if (textureIndex == textures.size())
        textureIndex = 0;
    
    this->setMainTexture(textures.at(textureIndex));
}

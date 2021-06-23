#include "Sprite.h"

#include "../rendering/Renderer.h"
#include "../core/Logger.h"

using namespace light2d::objects;

Sprite::Sprite(std::string filepath, core_graphics::TextureConfig config) {
    this->texFilePath = filepath;
    this->texConfig = config;
}

Sprite::Sprite(core_graphics::TextureConfig config) {
    this->texFilePath = "";
    this->texConfig = config;
}

Sprite::~Sprite() {
    if (ownTexture)
        delete mainTexture;
    
    if (ownMaterial) {
        delete material;
    }
    
    delete mesh;
}
    
void Sprite::init() {
    this->material = new materials::SpriteMaterial();
    this->material->init();
    
    if (!texFilePath.empty()) {
        mainTexture = new core_graphics::Texture();
        mainTexture->create(texFilePath, texConfig);
        this->material->setMainTexture(mainTexture);
        ownTexture = true;
        init_mesh(this->material->getMainTexture()->getWidth(), this->material->getMainTexture()->getHeight());
    }
    else {
        init_mesh(1, 1);
    }
}

void Sprite::init(materials::SpriteMaterial* material) {
    mainTexture = new core_graphics::Texture();
    mainTexture->create(texFilePath, texConfig);
    
    this->material = material;
    ownMaterial = false;
    
    this->material->setMainTexture(mainTexture);
    
    init_mesh(mainTexture->getWidth(), mainTexture->getHeight());
}

void Sprite::init_mesh(int size_x, int size_y) {
    mesh = new rendering::Mesh();
    
    std::vector<float> vertices = {
        // Position           // Tex coords
        -size_x/2.f,  size_y/2.f,   0.f, 1.f,
         size_x/2.f,  size_y/2.f,   1.f, 1.f,
         size_x/2.f, -size_y/2.f,   1.f, 0.f,
        -size_x/2.f, -size_y/2.f,   0.f, 0.f
    };
    
    std::vector<uint32_t> indices = {
        0, 1, 2,
        2, 3, 0
    };
    
    core_graphics::VertexBufferLayout layout = core_graphics::VertexBufferLayout();
    layout.addAttribute(core_graphics::VertexBufferAttributeType::Float, 2, false);
    layout.addAttribute(core_graphics::VertexBufferAttributeType::Float, 2, false);
    
    mesh->setData(vertices, true, indices, layout);
}

void Sprite::setMainTexture(core_graphics::Texture* texture, bool refreshMesh) {
    if (ownTexture) {
        delete this->mainTexture;
        ownTexture = false;
    }
    
    this->mainTexture = texture;
    this->material->getTextures()->at(0) = mainTexture;
    
    if (refreshMesh) {
        mesh->destroy();
        delete mesh;
    
        init_mesh(mainTexture->getWidth(), mainTexture->getHeight());
    }
}

void Sprite::render() {
    if (mainTexture == nullptr)
        return;
    
    rendering::Renderer::drawMesh(mesh, *getTransform(), material);
}

void Sprite::destroy() {
    if (ownMaterial) material->destroy();
    if (ownTexture)  mainTexture->destroy();
    mesh->destroy();
}
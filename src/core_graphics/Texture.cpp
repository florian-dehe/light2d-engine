#include "Texture.h"

#include "../third_party/stb/stb_image.h"

#include <GL/glew.h>

#include "../core/Logger.h"

using namespace light2d::core_graphics;

Texture::Texture() {
}

Texture::~Texture() {
}

void Texture::create(std::string filepath, TextureConfig config) {
    
    glGenTextures(1, &object_id);
    
    glBindTexture(GL_TEXTURE_2D, object_id);
    
    int wrap;
    int filter;
    int mipFilter;
    
    switch (config.wrapping) {
        case TextureConfig::TextureWrapping::REPEAT :           wrap = GL_REPEAT;           break;
        case TextureConfig::TextureWrapping::MIRRORED_REPEAT :  wrap = GL_MIRRORED_REPEAT;  break;
        case TextureConfig::TextureWrapping::CLAMP_TO_BORDER :  wrap = GL_CLAMP_TO_BORDER;  break;
        case TextureConfig::TextureWrapping::CLAMP_TO_EDGE :    wrap = GL_CLAMP_TO_EDGE;    break;
    }
    
    switch (config.filter) {
            case TextureConfig::TextureFiltering::NONE : filter = GL_NEAREST; break;
            case TextureConfig::TextureFiltering::NEAREST : filter = GL_NEAREST; break;
            case TextureConfig::TextureFiltering::LINEAR : filter = GL_LINEAR; break;
        }
    
    if (config.mipmap) {
        switch (config.mipmapFilter) {
            case TextureConfig::TextureFiltering::NONE :  {
                if (config.filter == TextureConfig::TextureFiltering::LINEAR) {
                    mipFilter = GL_LINEAR;
                }
                else {
                    mipFilter = GL_NEAREST;
                }
                
                break;
            }
            case TextureConfig::TextureFiltering::NEAREST : {
                if (config.filter == TextureConfig::TextureFiltering::LINEAR) {
                    mipFilter = GL_LINEAR_MIPMAP_NEAREST;
                }
                else {
                    mipFilter = GL_NEAREST_MIPMAP_NEAREST;
                }
                break;
            };
            case TextureConfig::TextureFiltering::LINEAR : {
                if (config.filter == TextureConfig::TextureFiltering::LINEAR) {
                    mipFilter = GL_LINEAR_MIPMAP_LINEAR;
                }
                else {
                    mipFilter = GL_NEAREST_MIPMAP_LINEAR;
                }
                break;
            };
        }
    }
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mipFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    
    stbi_set_flip_vertically_on_load(true);
    
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        this->width = width;
        this->height = height;
        
        int format = GL_RGBA;
        if (nrChannels < 4)
            format = GL_RGB;
        
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        
        if (config.mipmap)
            glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        core::Logger::get()->error("STB Image Loading", "Failed to load : " + filepath);
    }
    stbi_image_free(data);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind(int slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, object_id);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::destroy() {
    glDeleteTextures(1, &object_id);
}

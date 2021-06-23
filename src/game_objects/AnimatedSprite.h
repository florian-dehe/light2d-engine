#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "Sprite.h"
#include <vector>
#include <string>

namespace light2d {
    namespace objects {
        class AnimatedSprite : public Sprite {
        public:
            /**
             * @brief Constructor.
             * @param filePaths The file paths for the animation.
             * @param config The texture config to apply.
             * @param fps The animation fps.
             */
            AnimatedSprite(std::vector<std::string> filePaths, core_graphics::TextureConfig config, float fps);
            /**
             * @brief Destructor.
             */
            virtual ~AnimatedSprite();
            
            /**
             * @brief Inits the animated sprite.
             */
            void init() override;
            
            /**
             * @brief Inits the animated sprite with the given material.
             * @param material The material to apply derived from SpriteMaterial.
             */
            void init(materials::SpriteMaterial* material);
            
            /**
             * @brief Updates the animated sprite.
             */
            void update(double delta);
        private:
            std::vector<std::string> filePaths;
            std::vector<core_graphics::Texture*> textures;
            core_graphics::TextureConfig config;
            float fps;
            
            double currentTime = 0.0;
            
            int textureIndex = 0;
            
            void init_textures();
            void swap_texture();
        };
    }
}

#endif /* ANIMATEDSPRITE_H */


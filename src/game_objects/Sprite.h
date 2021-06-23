#ifndef SPRITE_H
#define SPRITE_H

#include "GameObject.h"
#include "../core_graphics/Texture.h"
#include "../rendering/Material.h"
#include "../rendering/Mesh.h"

#include "../materials/SpriteMaterial.h"

namespace light2d {
    namespace objects {
        /**
         * @brief Represents a basic sprite.
         */
        class Sprite : public GameObject {
        public:
            /**
             * @brief Constructor.
             * @details Textures are loaded during the init() method.
             * @param filepath The texture to load.
             * @param config The texture config to apply.
             */
            Sprite(std::string filepath, core_graphics::TextureConfig config);
            /**
             * @brief Constructor without texture.
             * @param config The texture config to apply.
             */
            Sprite(core_graphics::TextureConfig config);
            /**
             * @brief Destructor.
             */
            virtual ~Sprite();
            
            /**
             * @brief Inits the sprite.
             * @details Loads a template material.
             */
            void init() override;
            
            /**
             * @brief Inits the sprite with the given material.
             * @param material The material to apply derived from SpriteMaterial.
             */
            void init(materials::SpriteMaterial* material);
            
            /**
             * @brief Sets the main texture.
             * @param texture The texture to set.
             * @param refreshMesh Does the mesh needs to be refreshed ?
             */
            void setMainTexture(core_graphics::Texture* texture, bool refreshMesh=false);
            
            /**
             * @brief Renders the sprite.
             */
            void render();
            
            /**
             * @brief Destroys the sprite.
             */
            void destroy() override;
            
            /**
             * @brief Gets the current sprite material.
             * @return The current material.
             */
            inline materials::SpriteMaterial* getMaterial() { return this->material; }
            
        protected:
            core_graphics::Texture* mainTexture = nullptr;
        private:
            bool ownMaterial = true;
            materials::SpriteMaterial* material = nullptr;
            
            bool ownTexture = false;
            std::string texFilePath;
            core_graphics::TextureConfig texConfig;
            
            rendering::Mesh* mesh = nullptr;
            
            void init_mesh(int size_x, int size_y);
        };
    }
}

#endif /* SPRITE_H */


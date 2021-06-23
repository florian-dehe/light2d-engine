#ifndef SPRITEMATERIAL_H
#define SPRITEMATERIAL_H

#include "../rendering/Material.h"

namespace light2d {
    /**
     * @brief The namespace for materials templates.
     */
    namespace materials {
        /**
         * @brief This class is a material template for drawing sprites.
         */
        class SpriteMaterial : public rendering::Material {
        public:
            /**
             * @brief Constructor.
             */
            SpriteMaterial();
            /**
             * @brief Destructor.
             */
            virtual ~SpriteMaterial();
            
            /**
             * @brief Inits the sprite material.
             * @details Creates the associated shader.
             */
            void init() override;
            /**
             * @brief Destroys the sprite material.
             * @details Destroys all its own created ressources.
             */
            void destroy() override;
            
            /**
             * @brief Sets the main color.
             * @param mainColor The main color to set.
             */
            void setMainColor(glm::vec4 mainColor);
            /**
             * @brief Gets the main color.
             * @return The main color.
             */
            inline glm::vec4 getMainColor() { return this->mainColor; }
            
            /**
             * @brief Sets the main texture.
             * @return The old texture. Null ptr if there is no one.
             */
            core_graphics::Texture* setMainTexture(core_graphics::Texture* mainTexture);
            /**
             * @brief Gets the main texture.
             * @return The main texture.
             */
            inline core_graphics::Texture* getMainTexture() { return this->mainTexture; }
            
        private:
            core_graphics::Shader* spriteShader = new core_graphics::Shader();
            core_graphics::Texture* mainTexture = nullptr;
            glm::vec4 mainColor = glm::vec4(1.f);
        };
    }

}

#endif /* SPRITEMATERIAL_H */


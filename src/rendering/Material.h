#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>
#include <vector>

#include "../core_graphics/Shader.h"
#include "../core_graphics/Texture.h"

namespace light2d {
    namespace rendering {
        /**
         * @brief Represents a material. Manages textures and colors for a shader.
         */
        class Material {
        public:
            /**
             * @brief Init method.
             * @details Used by derivated classes to manage their own ressources.
             */
            virtual void init() { };
            
            /**
             * @brief Binds the material.
             */
            void bind();
            /**
             * @brief Unbinds the material.
             */
            void unbind();
            
            /**
             * @brief Destroy method.
             * @details Used by derivated classes to manage their own ressources.
             */
            virtual void destroy() { };
            
            /**
             * @brief Gets the shader.
             * @return The shader used by the material.
             */
            inline core_graphics::Shader* getShader() { return this->shader; }
            
            /**
             * @brief Gets the colors list.
             * @return The material color list.
             */
            inline std::vector<glm::vec4>* getColors() { return &this->colors;};
            /**
             * @brief Gets the texture list.
             * @param texture The material texture list.
             */
            inline std::vector<core_graphics::Texture*>* getTextures() { return &this->textures; };
            
        protected:
            /**
             * @brief Sets the shader to use.
             * @param shader The shader to use.
             */
            void setShader(core_graphics::Shader* shader);
        private:
            core_graphics::Shader* shader = nullptr;
            
            std::vector<core_graphics::Texture*> textures = std::vector<core_graphics::Texture*>();
            std::vector<glm::vec4> colors = std::vector<glm::vec4>();
        };
    }
}

#endif /* MATERIAL_H */


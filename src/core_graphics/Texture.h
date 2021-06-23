#ifndef TEXTURE_H
#define TEXTURE_H

#include <cstdint>
#include <string>

namespace light2d {
    namespace core_graphics {
        /**
         * @brief Config data for loading a texture.
         */
        struct TextureConfig {
            /**
             * @brief Texture wrapping options enum.
             */
            enum TextureWrapping {
                REPEAT = 0,
                MIRRORED_REPEAT = 1,
                CLAMP_TO_EDGE = 2,
                CLAMP_TO_BORDER = 3
            };
            
            /**
             * @brief Texture filtering options enum.
             */
            enum TextureFiltering {
                NONE = 0,
                NEAREST = 1,
                LINEAR = 2
            };
            
            /**
             * @brief The wrapping option to load the texture.
             */
            TextureWrapping wrapping;
            /**
             * @brief The filtering option to load the texture.
             */
            TextureFiltering filter;
            
            /**
             * @brief Do we have to generate mipmaps ?
             */
            bool mipmap;
            /**
             * @brief The filter option associated with the mipmap option.
             * @details Ignored if mimap is false.
             */
            TextureFiltering mipmapFilter = TextureFiltering::NONE;
            
        };
        
        /**
         * @brief Represents an OpenGL texture object.
         */
        class Texture {
        public:
            /**
             * @brief Constructor.
             */
            Texture();
            /**
             * @brief Destructor.
             */
            virtual ~Texture();
            
            /**
             * @brief Creates a texture object with the given configuration.
             * @param filepath The texture filepath to load.
             * @param config The texture configuration to use.
             */
            void create(std::string filepath, TextureConfig config);
            
            /**
             * @brief Binds the texture at the given slot.
             * @param slot The texture slot.
             */
            void bind(int slot);
            /**
             * @brief Unbinds the texture object.
             */
            void unbind();
            
            /**
             * @brief Destroys the texture object.
             */
            void destroy();
            
            /**
             * @brief Gets the texture width.
             * @return The texture width.
             */
            inline int getWidth() { return this->width; }
            
            /**
             * @brief Gets the texture height.
             * @return The texture height.
             */
            inline int getHeight() { return this->height; }
        private:
            uint32_t object_id;
            
            int width;
            int height;
        };
    }
}

#endif /* TEXTURE_H */


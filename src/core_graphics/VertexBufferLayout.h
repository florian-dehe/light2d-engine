#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <cstdint>
#include <vector>

#include <GL/glew.h>

#include "VertexBufferAttribute.h"

namespace light2d {
    namespace core_graphics {
        /**
         * @brief Represents a layout for a VertexBuffer used by a VertexArray.
         */
        class VertexBufferLayout {
        public:
            /**
             * @brief Constructor
             */
            VertexBufferLayout();
            /**
             * @brief Destructor
             */
            virtual ~VertexBufferLayout();
            
            /**
             * @brief Gets the stride of the layout.
             * @return The stride of the layout.
             */
            inline uint32_t getStride() { return this->stride; }
            
            /**
             * @brief Adds an attribute to the layout described by the given parameters.
             * @param type The data type.
             * @param size The data count (3 for vec3).
             * @param normalized The data needs to be normalized ? [-1, 1] or [0, 1]
             */
            void addAttribute(VertexBufferAttributeType type, uint32_t size, bool normalized);
            /**
             * @brief Gets the attribute list.
             * @return The list of the attributes.
             */
            inline std::vector<VertexBufferAttribute> getAttributes() { return this->attributes; }
            
            /**
             * @brief Gets the size of the layout ("how many values per vertex").
             * @return The size of the layout "in values".
             */
            inline uint32_t getLayoutSize() { return this->layoutSize; }
            
            /**
             * @brief Transformation from VertexBufferAttributeType to the equivalent GLenum.
             * @param type The VertexBufferAttributeType type.
             * @return The equivalent GLenum.
             */
            static GLenum attributeTypeToGLenum(VertexBufferAttributeType type);
        private:
            std::vector<VertexBufferAttribute> attributes;
            uint32_t stride = 0;
            
            uint32_t layoutSize = 0;
        };
    }
}

#endif /* VERTEXBUFFERLAYOUT_H */


#ifndef VERTEXBUFFERATTRIBUTE_H
#define VERTEXBUFFERATTRIBUTE_H

#include <cstdint>

namespace light2d {
    namespace core_graphics {
        /**
         * @brief The vertex buffer attribute type for a VertexBufferAttribute.
         */
        enum VertexBufferAttributeType : uint32_t {
            /**
             * @brief Represents the float type.
             */
            Float = 0,
            /**
             * @brief Represents the int type.
             */
            Int = 1,
            /**
             * @brief Represents the bool type.
             */
            Bool = 2,
        };
        
        /**
         * @brief Represents an attribute in a VertexBufferLayout.
         */
        struct VertexBufferAttribute {
            /**
             * The size of the attribute (3 if vec3).
             */
            uint32_t size;
            /**
             * The type of the attribute
             * @see VertexBufferAttributeType
             */
            VertexBufferAttributeType type;
            /**
             * Is the data normalized ?
             */
            bool normalized = false;
            /**
             * The offset of the attribute.
             * Automaticaly referenced by VertexBufferLayout.
             */
            uint64_t offset;
        };
    }
}
#endif /* VERTEXBUFFERATTRIBUTE_H */


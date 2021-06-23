#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <cstdint>

#include "GraphicsBuffer.h"
#include "VertexBufferLayout.h"


namespace light2d {
    /**
     * @brief Namespace used for the core classes for graphics.
     */
    namespace core_graphics {
        /**
         * @brief Represents an OpenGL Vertex Buffer object.
         * @details Needs to be created with the method create() in order to be used properly.
         */
        class VertexBuffer : public GraphicsBuffer {
        public:
            /**
             * @brief Constructor.
             */
            VertexBuffer();
            /**
             * @brief Desctructor.
             */
            virtual ~VertexBuffer();
            
            /**
             * @brief Creates the vertex buffer object.
             * @param data_size The size of the data given in bytes.
             * @param data The data itself.
             */
            virtual void create(uint32_t data_size, const void* data) override;
            
            /**
             * @brief Binds the buffer.
             */
            virtual void bind() override;
            /**
             * @brief Unbinds th buffer.
             */
            virtual void unbind() override;
            
            /**
             * @brief Destroys the buffer.
             */
            virtual void destroy() override;
        };
    }
}

#endif /* VERTEXBUFFER_H */


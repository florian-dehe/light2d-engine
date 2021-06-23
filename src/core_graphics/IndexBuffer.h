#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include <cstdint>

#include "GraphicsBuffer.h"

namespace light2d {
    namespace core_graphics {
        /**
         * @brief Represents an OpenGL Element Array Buffer object.
         * @details Needs ti be created with create() in order to be used properly.
         */
        class IndexBuffer : public GraphicsBuffer {
        public:
            /**
             * @brief Constructor
             */
            IndexBuffer();
            /**
             * @brief Destuctor
             */
            virtual ~IndexBuffer();
            
            /**
             * @brief Creates the vertex buffer object. 
             * @details Expects a uint32_t array as data parameter.
             * @param data_count The size of the data given in bytes.
             * @param data The data itself (expecting uint32_t array).
             */
            virtual void create(uint32_t data_count, const void* data) override;
            
            /**
             * @brief Binds the buffer.
             */
            virtual void bind() override;
            /**
             * @brief Unbinds th buffer.
             */
            virtual void unbind() override;
            
            /**
             * @brief Destroys the buffer
             */
            virtual void destroy() override;
            
            /**
             * @brief Gets the number of indices.
             * @return The number of indices.
             */
            inline uint32_t getIndexCount() { return this->indexCount; }
        private:
            uint32_t indexCount;
        };
    }
}

#endif /* INDEXBUFFER_H */


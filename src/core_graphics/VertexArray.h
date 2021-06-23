#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <memory>

namespace light2d {
    namespace core_graphics {
        /**
         * @brief Represents a vertex array object.
         * @details In order to render something you need to set a vertex buffer.
         */
        class VertexArray {
        public:
            /**
             * @brief Constructor.
             * @param layout The layout of the data transmitted by the VertexBuffer.
             */
            VertexArray(VertexBufferLayout layout);
            /**
             * @brief Destructor.
             */
            virtual ~VertexArray();
            /**
             * @brief Creates the vertex array object.
             */
            void create();
            
            /**
             * @brief Binds the VertexArray.
             */
            void bind();
            /**
             * @brief Unbinds the VertexArray.
             */
            void unbind();
            
            /**
             * @brief Destroys the vertex array object.
             */
            void destroy();
            
            /**
             * @brief Sets the vertex buffer to associate with the vertex array object.
             * @details Applies the layout into the vertex array object.
             * @param vertexBuffer The VertexBuffer to associate with.
             */
            void setVertexBuffer(VertexBuffer* vertexBuffer);
            
            /**
             * @brief Sets the index buffer to associate with the vertex array object.
             * @param indexBuffer The IndexBuffer to associate with.
             */
            void setIndexBuffer(IndexBuffer* indexBuffer);
            
            /**
             * @brief Gets the count of indices in indexBuffer if it exists.
             * @details If there are no IndexBuffer, returns 0;
             * @return the number of indices in the IndexBuffer or 0 if no one.
             */
            inline uint32_t getIndexCount() { return this->indexBuffer != nullptr ? this->indexBuffer->getIndexCount() : 0; }
        private:
            uint32_t object_id;

            VertexBufferLayout layout;
            VertexBuffer* vertexBuffer = nullptr;
            IndexBuffer* indexBuffer = nullptr;
        };
    }
}

#endif /* VERTEXARRAY_H */


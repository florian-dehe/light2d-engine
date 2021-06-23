#ifndef GRAPHICSBUFFER_H
#define GRAPHICSBUFFER_H

namespace light2d {
    namespace core_graphics {
        /**
         * @brief Represents a graphics buffer. Can't be instanciated.
         * @details Used as a model for the classes VertexBuffer and IndexBuffer.
         */
        class GraphicsBuffer {
        public:
            /**
             * Creates the buffer with the given parameters.
             * @param data_size The size of the buffer.
             * @param data The data attached to the buffer. 
             */
            virtual void create(uint32_t data_size, const void* data) = 0;
            
            /**
             * Binds the buffer.
             */
            virtual void bind() = 0;
            /**
             * Unbinds the buffer.
             */
            virtual void unbind() = 0;
            
            /**
             * Destroys the buffer.
             */
            virtual void destroy() = 0;
        protected:
            /**
             * The buffer id.
             */
            uint32_t buffer_id = 0;
        };
    }
}

#endif /* GRAPHICSBUFFER_H */


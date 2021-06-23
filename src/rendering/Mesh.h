#ifndef MESH_H
#define MESH_H

#include "../core_graphics/VertexArray.h"

namespace light2d {
    namespace rendering {
        /**
         * @brief Represents a set of vertices and indices managed by OpenGL objects.
         */
        class Mesh {
        public:
            /**
             * @brief Constructor.
             */
            Mesh();
            /**
             * @brief Destructor.
             */
            virtual ~Mesh();
            
            /**
             * @brief Sets the data to the mesh. "Creates" the mesh.
             * @details Creates all the necessary objects to manage the verties and the indices.
             * @param vertices The vertices to load.
             * @param indexed Is the data indexed. If yes, uses the indices vector given.
             * @param indices The indices to load.
             * @param layout The layout of the given vertices.
             */
            void setData(std::vector<float> vertices, bool indexed, std::vector<uint32_t> indices, core_graphics::VertexBufferLayout layout);
            
            /**
             * @brief Activates the mesh for drawing.
             */
            void bind();
            /**
             * @brief Deactivates the mesh for drawing.
             */
            void unbind();
            
            /**
             * @brief Get the number of indices.
             * @return The number of indices.
             */
            uint32_t getIndexCount();
            /**
             * @brief Gets the number of vertices in the data.
             * @return The number of vertices in the data.
             */
            uint32_t getVertexCount();
            
            /**
             * @brief Destroys the mesh and all the objects created.
             */
            void destroy();
            
            /**
             * @brief Returns true if the mesh is indexed.
             * @details Used by the Renderer to correctly draw the data.
             * @return true if the data is indexed.
             */
            inline bool isIndexed() { return this->indexed; } 
        private:
            bool indexed = false;
            uint32_t vertexCount = 0;
            
            core_graphics::VertexArray* vao = nullptr;
            core_graphics::VertexBuffer* vbo = nullptr;
            core_graphics::IndexBuffer* ebo = nullptr;
        };
    }
}
#endif /* MESH_H */


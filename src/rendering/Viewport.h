#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <glm/glm.hpp>

namespace light2d {
    namespace rendering {
        /**
         * @brief This class represents a viewport.
         * @details Modifies a projection matrix in OpenGL.
         */
        class Viewport {
        public:
            /**
             * @brief Constructor.
             */
            Viewport(int width, int height);
            /**
             * @brief Destructor.
             */
            virtual ~Viewport();
            
            /**
             * @brief Resizes the viewport.
             * @param width The new width of the viewport.
             * @param height The new height of the viewport.
             */
            void resize(int width, int height);
            
            /**
             * @brief Returns the projection matrix.
             * @return The projection matrix.
             */
            inline glm::mat4 getProjectionMatrix() { return this->projection; }
            
            /**
             * @brief Gets the viewport width.
             * @return The viewport currtent width.
             */
            inline int getWidth() { return this->width; }
            
            /**
             * @brief Gets the viewport height.
             * @return The viewport height.
             */
            inline int getHeight() { return this->height; }
        private:
            int width;
            int height;
            glm::mat4 projection = glm::mat4(1.f);
        };
    }
}

#endif /* VIEWPORT_H */


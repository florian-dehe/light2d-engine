#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

namespace light2d {
    /**
     * @brief This namespace contains all the classes related to rendering (Camera, Viewport, Renderer...)
     */
    namespace rendering {
        /**
         * @brief This class represents a camera for the scene.
         * @details Modifies a view matrix in OpenGL.
         */
        class Camera {
        public:
            /**
             * @brief Constructor
             */
            Camera();
            /**
             * @brief Destructor
             */
            virtual ~Camera();
            
            /**
             * @brief Moves the camera by the given vector.
             * @param move The vector to add to the position.
             */
            void move(glm::vec2 move);
            /**
             * @brief Sets the position.
             * @param pos The position to set.
             */
            void setPosition(glm::vec2 pos);
            
            /**
             * @brief Zooms the camera.
             * @param zoom The zoom factor to apply.
             */
            void zoom(float zoom);
            /**
             * @brief Sets the zoom with the given factor.
             * @param zoom The zoom factor to set.
             */
            void setZoom(float zoom);
            
            /**
             * @brief Resets the camera.
             * @details Resets the view matrix.
             */
            void reset();

            /**
             * @brief Returns the view matrix.
             * @return The view matrix.
             */
            inline glm::mat4 getViewMatrix() { return this->view; }
        private:
            float zoomFactor;
            glm::vec2 pos = glm::vec2(0.f);
            
            glm::mat4 view = glm::mat4(1.f);
            
            void applyTransform();
        };
    }
}

#endif /* CAMERA_H */


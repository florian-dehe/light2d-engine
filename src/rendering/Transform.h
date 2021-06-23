#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>

namespace light2d {
    namespace rendering {
        /**
         * @brief Represents an object transform. Used to move, rotate or scale objects.
         * @details Manipulates an OpenGL model matrix.
         */
        class Transform {
        public:
            /**
             * @brief Constructor.
             */
            Transform();
            /**
             * @brief Destructor.
             */
            virtual ~Transform();
            
            /**
             * @brief Resets the transform matrix.
             */
            void reset();
            
            /**
             * @brief Adds moveVector to current position.
             * @param moveVector The vector to add.
             */
            void move(glm::vec2 moveVector);
            /**
             * @brief Sets the position.
             * @param position The position to set.
             */
            void setPosition(glm::vec2 position);
            /**
             * @brief Gets the current position.
             * @return The current position.
             */
            inline glm::vec2 getPosition() { return this->position; }
            
            /**
             * @brief Adds degrees to the current rotation.
             * @param degrees The degrees to add.
             */
            void rotate(float degrees);
            /**
             * @brief Sets the rotation degrees.
             * @param degrees The rotation degrees to set.
             */
            void setRotation(float degrees);
            /**
             * @brief Gets the rotation in degrees.
             * @return The rotation in degrees.
             */
            inline float getRotationDegrees() { return this->rotationDegrees; }
            
            /**
             * @brief Scales from the current scale.
             * @param scaleVector The scale vector to apply.
             */
            void scale(glm::vec2 scaleVector);
            /**
             * @brief Sets the scale of the vector.
             * @param scale
             */
            void setScale(glm::vec2 scale);
            /**
             * @brief Gets the current scale
             * @return A scale vector.
             */
            inline glm::vec2 getScale() { return this->scaleVector; }
            
            /**
             * @brief Gets the model matrix.
             * @return The model matrix
             */
            inline glm::mat4 getModelMatrix() { return this->model; }
        private:
            glm::mat4 model = glm::mat4(1.0f);
            
            glm::vec2 position = glm::vec2(0.f);
            float rotationDegrees = 0.f;
            glm::vec2 scaleVector = glm::vec2(1.f);
            
            void applyTransform(glm::vec2 pos, float degrees, glm::vec2 scaleVector);
            void applyTransform();
        };
    }
}

#endif /* TRANSFORM_H */


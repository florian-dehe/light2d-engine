#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../rendering/Transform.h"

namespace light2d {
    /**
     * @brief Contains all the template game gameObjects.
     */
    namespace objects {
        /**
         * @brief Represents a game object.
         */
        class GameObject {
        public:
            /**
             * @brief Constructor.
             */
            GameObject() { }
            /**
             * @brief Destructor.
             */
            virtual ~GameObject() { }
            
            /**
             * @brief Init method.
             */
            virtual void init() = 0;

            /**
             * @brief Update method.
             */
            virtual void update() = 0;

            /**
             * @brief Render method.
             */
            virtual void render() = 0;
            
            /**
             * @brief Destroy method.
             */
            virtual void destroy() = 0;
            
            /**
             * @brief Gets the game object transform.
             * @return The object transform.
             */
            inline rendering::Transform* getTransform() { return &this->transform; }
        private:
            rendering::Transform transform;
        };
    }
}

#endif /* GAMEOBJECT_H */


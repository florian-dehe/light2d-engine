#ifndef LIGHT2D_ENGINE_GAMEOBJECTGROUP_H
#define LIGHT2D_ENGINE_GAMEOBJECTGROUP_H

#include <vector>

#include "GameObject.h"

namespace light2d {
    namespace objects {
        /**
         * @brief Represents a group of objects. Used to better manage them in game.
         */
        class GameObjectGroup {
        public:
            /**
             * @brief Constructor.
             */
            GameObjectGroup() { }
            /**
             * @brief Destructor.
             */
            ~GameObjectGroup() { }

            /**
             * @brief Inits all the members of the group.
             */
            void init();
            /**
             * @brief Updates all the members of the group.
             */
            void update();
            /**
             * @brief Renders all the members of the group.
             */
            void render();
            /**
             * @brief Destroys all the members of the group.
             */
            void destroy();

            /**
             * @brief Adds an object to the group if he doesn't exist in this group already.
             * @param gameObject The game object to add to the group.
             */
            void addObject(GameObject* gameObject);
            /**
             * @brief Removes an object from the group if he is in the group already.
             * @param gameObject The game object to remove from the group.
             */
            void removeObject(GameObject* gameObject);

            /**
             * @brief Tests if the object is present in the group.
             * @param gameObject The object to test.
             * @return True if the object is in the group.
             */
            bool isInGroup(GameObject* gameObject);

        private:
            std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
            std::vector<GameObject*>::iterator findIterator(GameObject* gameObject);
        };

    }
}


#endif //LIGHT2D_ENGINE_GAMEOBJECTGROUP_H

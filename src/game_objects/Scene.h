#ifndef SCENE_H
#define SCENE_H

namespace light2d {
    namespace objects {
        /**
         * @brief Represents a model for the game cycle.
         */
        class Scene {
        public:
            /**
             * @brief Constructor
             */
            Scene() { }
            /**
             * @brief Destructor
             */
            virtual ~Scene() { }
            
            /**
             * @brief OnInit scene event.
             * @details Should be defined and used by the user.
             */
            virtual void onInit() = 0;
            /**
             * @brief OnRender scene event.
             * @details Should be defined and used by the user.
             */
            virtual void onRender() = 0;
            
            /**
             * @brief OnUpdate scene event.
             * @details Called after onRender(). Should be defined and used by the user.
             * @param delta The time between each frame.
             */
            virtual void onUpdate(double delta) = 0;
            
            /**
             * @brief OnDestroy scene event.
             * @details Should be defined and used by the user.
             */
            virtual void onDestroy() = 0;
        };
    }
}

#endif /* SCENE_H */


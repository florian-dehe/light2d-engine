#ifndef LIGHT2D_ENGINE_SIMPLEAPPLICATION_H
#define LIGHT2D_ENGINE_SIMPLEAPPLICATION_H

#include "Application.h"

namespace light2d {
    namespace core {
        /**
         * @brief Provides a simple Application implementation without any events.
         */
        class SimpleApplication : public Application {
        public:
            /**
             * @brief Constructor
             * @param title Title of the window
             * @param width Width of the window
             * @param height Height of the window.
             */
            SimpleApplication(std::string title, int width, int height);

            /**
             * @brief Destructor
             */
            virtual ~SimpleApplication() { }

        protected:

            /**
             * @brief Initialization event. Empty in this case.
             */
            void onInit() override { }

            /**
             * @brief Rendering event. Empty in this case.
             */
            void onRender() override { }

            /**
             * @brief Update event. Empty in this case.
             * @param delta The time delta between two frames.
             */
            void onUpdate(double delta) override { }
            /**
             * @brief Destroy event. Empty in this case.
             */
            void onDestroy() override { }

        };
    }
}


#endif //LIGHT2D_ENGINE_SIMPLEAPPLICATION_H

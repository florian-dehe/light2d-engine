#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"
#include <chrono>

#include "../game_objects/Scene.h"

/**
 * @brief Library's namespace
 */
namespace light2d {
    /**
     * @brief Core library namespace
     */
    namespace core {
        /**
         * @brief Represents a Light2D game application.
         * 
         * @details This class has to be inherited by the user app class which will define the
         * following methods : onInit(), onRender(), onUpdate(), onRender(). These methods
         * offer the control over the application as the user doesn't have the access on the game loop.
         */
        class Application {
        public:
            /**
             * @brief Constructor
             * @details Creates a Window object.
             * @param title The title of the window.
             * @param width The width of the window.
             * @param height The height of the window.
             */
            Application(std::string title, int width, int height);
            /**
             * @brief Destructor.
             */
            virtual ~Application();
            
            /**
             * @brief Initialize the window object.
             */
            void init();
            /**
             * @brief Destroys the window object.
             */
            void destroy();
            
            /**
             * @brief OnInit application event.
             * @details Should be defined and used by the user.
             */
            virtual void onInit() = 0;
            /**
             * @brief OnRender application event.
             * @details Should be defined and used by the user.
             */
            virtual void onRender() = 0;
            
            /**
             * @brief OnUpdate application event.
             * @details Called after onRender(). Should be defined and used by the user.
             * @param delta The time between each frame.
             */
            virtual void onUpdate(double delta) = 0;
            
            /**
             * @brief OnDestroy application event.
             * @details Should be defined and used by the user.
             */
            virtual void onDestroy() = 0;
            
            /**
             * @brief Runs the application.
             * @details Launches the game loop.
             * @param startScene The scene to start with.
             */
            void run(objects::Scene* startScene);
            
            /**
             * @brief Quits the application.
             */
            void quit();
            
            /**
             * @brief Gets the current window width.
             * @return The current window width. 
             */
            int getWindowWidth();
            
            /**
             * @brief Gets the current window height.
             * @return The current window height.
             */
            int getWindowHeight();
            
            /**
             * @brief Loads an icon to set for the window.
             * @param filepath the icon to load.
             */
            void setWindowIcon(std::string filepath);
            
            /**
             * @brief Changes the current scene displayed.
             * @param newScene The new scene to change.
             * @return The previous scene destroyed. Returns nullptr if newScene is nullptr.
             */
            objects::Scene* changeSceneTo(objects::Scene* newScene);
        
        private:
            bool isRunning = true;
            
            Window* window = nullptr;
            
            objects::Scene* currentScene = nullptr;
        };
    }
}

#endif /* APPLICATION_H */


#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace light2d {
    namespace core {
        /**
         * @brief Represents the game window.
         */
        class Window {
        public:
            /**
             * Constructor.
             * Stores the data for initialization.
             * @param title The window's title.
             * @param width The window's width.
             * @param height The window's height.
             */
            Window(std::string title, int width, int height);
            /**
             * @brief Destructor.
             */
            virtual ~Window();
            
            /**
             * @brief Initialize the game window.
             */
            void init();
            /**
             * @brief Destroys the game window.
             */
            void destroy();
            
            /**
             * @brief Begins a frame.
             * @details Clears the screen.
             */
            void beginFrame();
            /**
             * @brief Ends the frame.
             * @details Updates the window, gets the user events.
             */
            void endFrame();
            
            /**
             * @brief Gets the state of the window.
             * @return Should the game window close ?
             */
            inline bool shouldClose() { return this->windowShouldClose; }
            
            /**
             * @brief Returns the current width;
             * @return The current width.
             */
            int getWidth();
            
            /**
             * @brief Returns the current height.
             * @return The current height.
             */
            int getHeight();
            
            /**
             * @brief Returns the last frame delta (Time between frames)
             * @return The last frame delta.
             */
            inline double getDelta() { return this->delta; }
            
            /**
             * @brief Loads an icon and sets it using the filepath parameter.
             * @param filepath The icon to load. 
             */
            void setIcon(std::string filepath);
            
        private:
            std::string title;
            int width;
            int height;
            
            bool windowShouldClose = false;
            
            // Time
            double delta = 0.0;
            double startFrameTime = 0.0;
            double endFrameTime = 0.0;
            
            GLFWwindow* win = nullptr;
            
            static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        };
    }
}

#endif /* WINDOW_H */


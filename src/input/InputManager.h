#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>

#include "Event.h"

struct GLFWwindow;

namespace light2d {
    namespace input  {
        /**
         * @brief Class which contains all the callbacks for getting input with GLFW. (Do not use).
         * @details Internal use only. Do not use. See Input class instead.
         */
        class InputManager {
        public:
            /**
             * @brief The GLFW callback to get the keyboard events.
             * @param win The GLFW window object.
             * @param key The key code.
             * @param scancode The key scancode.
             * @param action The key action.
             * @param mods The key modifiers.
             */
            static void keyCallback(GLFWwindow* win, int key, int scancode, int action, int mods);
            /**
             * @brief The GLFW callback to get the mouse position.
             * @param win The GLFW window object.
             * @param xpos The x position component.
             * @param ypos The y position component.
             */
            static void cursorPositionCallback(GLFWwindow* win, double xpos, double ypos);
            /**
             * @brief The GLFW callback to get the mouse button events.
             * @param win The GLFW window object.
             * @param button The button code.
             * @param action The button action.
             * @param mods The button modifiers.
             */
            static void mouseButtonCallback(GLFWwindow* win, int button, int action, int mods);
            /**
             * @brief The GLFW callback to get the mouse scroll event.
             * @param win The GLFW window object.
             * @param xoffset The x offset component.
             * @param yoffset The y offset component.
             */
            static void mouseScrollCallback(GLFWwindow* win, double xoffset, double yoffset);
            
            /**
             * @brief Sets if the InputManager has to log the events.
             * @param value Should we log the events ?
             */
            static void setLogEvents(bool value);
            
        private:
            static bool logEvents;
        };
    }
}

#endif /* INPUTMANAGER_H */


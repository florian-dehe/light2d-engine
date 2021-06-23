#ifndef INPUT_H
#define INPUT_H

#include "Event.h"
#include "EventQueue.h"

namespace light2d {
    namespace input {
        /**
         * @brief Static class to get the user events.
         */
        class Input {
        public:
            /**
             * @brief Gets the mouse position as a struct.s
             * @return The mouse position.
             */
            static MousePosition getMousePosition();
            
            /**
             * @brief Gets the event queue.
             * @return The event queue.
             */
            static EventQueue* getEventQueue();
            
            /**
             * @brief Is the key pressed ?
             * @param keycode The keycode to analyze.
             * @return The key is pressed.
             */
            static bool isKeyPressed(int keycode);
            /**
             * @brief Is the key just pressed ?
             * @param keycode The keycode to analyze.
             * @return The key is pressed this frame.
             */
            static bool isKeyJustPressed(int keycode);
            /**
             * @brief Is the key just released ?
             * @param keycode The keycode to analyze.
             * @return The key is released this frame.
             */
            static bool isKeyJustReleased(int keycode);
        private:
            friend class InputManager;
            static MousePosition mousePosition;
            static EventQueue* eventQueue;
        };

    }
}

#endif /* INPUT_H */


#ifndef EVENT_H
#define EVENT_H

#include <string>

#include "Key.h"

namespace light2d {
    namespace input {
        /**
         * @brief Represents the mouse position.
         * @details Also has the previous position.
         */
        struct MousePosition {
            /**
             * @brief The previous x position.
             * @details Equals -1.0 if there is no previous position.
             */
            double before_x = -1.0;
            /**
             * @brief The previous y position.
             * @details Equals -1.0 if there is no previous position.
             */
            double before_y = -1.0;
            
            /**
             * @brief The current x position value.
             */
            double x;
            /**
             * @brief The current y position value.
             */
            double y;
        };
        
        /**
         * @brief The type of event, in order to cast to good type the event pointer.
         */
        enum class EventType : int {
            /**
             * @brief Default value.
             */
            NONE = 0,
            /**
             * @brief Keyboard event value.
             */
            KEYBOARD = 1,
            /**
             * @brief Mouse Button event value.
             */
            MOUSE_BUTTON = 2,
            /**
             * @brief Mouse Scroll event value.
             */
            MOUSE_SCROLL = 3,
        };
        
        /**
         * @brief The event actions.
         * @details Same codes as GLFW.
         */
        enum class EventAction : int {
            /**
             * @brief Default value.
             */
            NONE = -1,
            
            /**
             * @brief The release action.
             */
            RELEASE = 0,
            /**
             * @brief The press action.
             */
            PRESS = 1,
            /**
             * @brief The repeat action.
             */
            REPEAT = 2
        };
        
        /**
         * @brief The event modifiers bits.
         */
        enum class EventModsBits : int {
            /**
             * @brief The shift bit.
             */
            SHIFT = 0x0001,
            /**
             * @brief The control bit.
             */
            CONTROL = 0x0002,
            /**
             * @brief The alt bit.
             */
            ALT = 0x0004,
            /**
             * @brief The super bit.
             */
            SUPER = 0x0008
        };
        
        /**
         * @brief Base class for all events.
         */
        class Event {
        public:
            /**
             * @brief The name of the value.
             */
            std::string name;
            /**
             * @brief The type of the event to cast to the good type.
             */
            EventType type = EventType::NONE;
        };
        
        /**
         * @brief The Keyboard event.
         */
        class KeyboardEvent : public Event {
        public:
            /**
             * @brief The keycode.
             */
            int key;
            /**
             * @brief The key scancode.
             */
            int scancode;
            /**
             * @brief The key action.
             */
            int action;
            /**
             * @brief The event modifiers.
             */
            int mods;
        };
        
        /**
         * @brief The mouse button event.
         */
        class MouseButtonEvent : public Event {
        public:
            /**
             * @brief The button code.
             */
            int button;
            /**
             * @brief The button action.
             */
            int action;
            /**
             * @brief The event modifiers.
             */
            int mods;
        };
        
        /**
         * @brief The mouse scroll event.
         */
        class MouseScrollEvent : public Event {
        public:
            /**
             * @brief The offset's x component.
             */
            double xoffset;
            /**
             * @brief The offset's y component.
             */
            double yoffset;
        };
    }
}


#endif /* EVENT_H */


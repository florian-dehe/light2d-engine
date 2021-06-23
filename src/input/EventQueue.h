#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue>
#include <set>

#include "Event.h"

namespace light2d {
    namespace input {
        /**
         * @brief Represents the events queue. Used by the Input class.
         */
        class EventQueue {
        public:
            /**
             * @brief Constructor
             */
            EventQueue();
            /**
             * @brief Destructor.
             */
            virtual ~EventQueue();
            
            /**
             * @brief Polls an event from the queue. (Destroys it from the queue)/
             * @return The event polled.
             */
            Event* poll();
            /**
             * @brief Pushes an event at the end of the queue.
             * @param evt
             */
            void pushBack(Event* evt);
            
            /**
             * @brief Clears the queue.
             */
            void clear();
            
            /**
             * @brief Is the queue empty ?
             * @return True if the queue is empty.
             */
            bool empty();
            
            /**
             * @brief Gets the key pressed.
             * @return the set of key pressed.
             */
            inline std::set<int> getKeyPressed() { return this->keyPressed; }
            /**
             * @brief Gets the key just pressed.
             * @return the set of key just pressed this frame.
             */
            inline std::set<int> getKeyJustPressed() { return this->keyJustPressed; }
            /**
             * @brief Gets the key just released.
             * @return the set of key just released this frame.
             */
            inline std::set<int> getKeyJustReleased() { return this->keyJustReleased; }
        private: 
            std::queue<Event*> queue;
            bool polled = false;
            
            std::set<int> keyPressed;
            std::set<int> keyJustPressed;
            std::set<int> keyJustReleased;
        };
    }
}

#endif /* EVENTQUEUE_H */


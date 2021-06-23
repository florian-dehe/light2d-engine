#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include <string>

namespace light2d {
    /**
     * @brief Namespace for drawing ui elements.
     */
    namespace ui {
        /**
         * @brief Represents an ImGui window.
         * @details Creates a window with the given parameters.
         */
        class GuiWindow {
        public:
            /**
             * @brief Constructor.
             * @param name The name of the window.
             * @param flags The window flags to add.
             */
            GuiWindow(std::string name, int flags=0);
            /**
             * @brief Destructor.
             */
            virtual ~GuiWindow();

            /**
             * @brief Renders the window.
             */
            void render();
            
            /**
             * @brief The method to be overriden to add content for this window.
             */
            virtual void onUpdate() = 0;
        
            /**
             * @brief Sets the visibility of the window.
             * @param value The visibility state.
             */
            void setVisible(bool value);
        private:
            std::string name;
            
            int windowFlags = 0;
            
            bool visible = true;
        };
    }

}

#endif /* GUIWINDOW_H */


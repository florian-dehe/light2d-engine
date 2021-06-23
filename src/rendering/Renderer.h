#ifndef RENDERER_H
#define RENDERER_H

#include "Viewport.h"
#include "Camera.h"
#include "Mesh.h"

#include "../core_graphics/Shader.h"

#include "Transform.h"
#include "Material.h"

namespace light2d {
    namespace rendering {
        /**
         * @brief This static class is used to draw anything on the screen.
         */
        class Renderer {
        public:
            /**
             * @brief Inits the renderer.
             * @details Creates a viewport with the given size and a camera.
             * @param width The width of the viewport.
             * @param height The height of the viewport.
             */
            static void init(int width, int height);
            
            /**
             * @brief Draws a mesh.
             * @details Activates the shader, pass the transforms matrix to it
             *          draw the mesh aaccording to its vertices and indices.
             * @param mesh The mesh to draw.
             * @param transform The object's transform.
             * @param material The material to apply for the drawing.
             */
            static void drawMesh(Mesh* mesh, Transform& transform, Material* material);
            
            /**
             * @brief Resizes the viewport created during initialization.
             * @param width The new width of the viewport.
             * @param height The new height of the viewport.
             */
            static void resizeViewport(int width, int height);
            
            /**
             * @brief Gets the current viewport width.
             * @return The current viewport width. 
             */
            static int getViewportWidth();
            /**
             * @brief Gets the current viewport height.
             * @return The current viewport height.
             */
            static int getViewportHeight();
            
            /**
             * @brief Gets the current Camera.
             * @return The current camera.
             */
            static Camera* getCurrentCamera();
            
            /**
             * @brief Sets the current camera.
             * @details Does not destroys the previous one.
             * @param camera The camera to set.
             */
            static void setCurrentCamera(Camera* camera);
            
        private:
            static bool initialized;
            static Viewport* viewport;
            static Camera* currentCamera;
        };
    }
}

#endif /* RENDERER_H */


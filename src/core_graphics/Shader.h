#ifndef SHADER_H
#define SHADER_H

#include <cstdint>
#include <string>

namespace light2d {
    namespace core_graphics {
        /**
         * @brief Represents an OpenGL shader program.
         */
        class Shader {
        public:
            /**
             * @brief Constructor.
             */
            Shader();
            /**
             * @brief Destructor.
             */
            virtual ~Shader();
            
            /**
             * @brief Creates a shader program with the path for the vertex shader and the fragment shader.
             * @details Compiles the shaders, attach them and links them to the program.
             * @param vertexPath The path to the vertex shader source file.
             * @param fragmentPath The path to the fragment shader source file.
             */
            void create(const char* vertexPath, const char* fragmentPath);
            
            /**
             * @brief Binds the shader program.
             */
            void bind();
            /**
             * @brief Unbinds the shader program.
             */
            void unbind();
            
            /**
             * @brief Destroys the shader program.
             */
            void destroy();
            
            // Uniforms
            /**
             * @brief Sets a float uniform
             * @param propertyName The name of the property to set.
             * @param value The value to set.
             */
            void setFloat(std::string propertyName, float value);
            /**
             * @brief Sets a float[2] uniform
             * @param propertyName The name of the property to set.
             * @param array The array to set.
             */
            void setFloat2(std::string propertyName, float* array);
            /**
             * @brief Sets a float[3] uniform
             * @param propertyName The name of the property to set.
             * @param array The array to set.
             */
            void setFloat3(std::string propertyName, float* array);
            /**
             * @brief Sets a float[4] uniform
             * @param propertyName The name of the property to set.
             * @param array The array to set.
             */
            void setFloat4(std::string propertyName, float* array);
            
            /**
             * @brief Sets an int uniform
             * @param propertyName The name of the property to set
             * @param value The value to set.
             */
            void setInt(std::string propertyName, int value);
            
            /**
             * @brief Sets a bool uniform
             * @param propertyName The name of the property to set
             * @param value The value to set.
             */
            void setBool(std::string propertyName, bool value);
            
            /**
             * @brief Sets a matrix4 uniform.
             * @param propertyName The name of the property to set.
             * @param transpose Does the matrix needs to be transposed ?
             * @param matrix_ptr The matrix raw pointer.
             */
            void setMatrix4(std::string propertyName, bool transpose, const float* matrix_ptr);
            
        private:
            uint32_t program_id;
            
            int checkUniformName(std::string propertyName);
        };
    }

}

#endif /* SHADER_H */


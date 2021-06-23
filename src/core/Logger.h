#ifndef LOGGER_H
#define LOGGER_H

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace light2d {
    namespace core {
        /**
         * @brief Used to log messages in the console. (Singleton)
         * 
         * @details Usage : Logger::get()->logMethod("Some message");
         * The logger's level is used to filter the messages that are sent to the console.
         */
        class Logger {
        public:
            /**
             * @brief The log level index for displaying info messages.
             */
            static const int LOG_LEVEL_INFO;
            /**
             * @brief The log level index for displaying info and warning messages.
             */
            static const int LOG_LEVEL_WARNING;
            /**
             * @brief The log level index for displaying info, warning and error messages.
             */
            static const int LOG_LEVEL_ERROR;
            /**
             * @brief The log level index for displaying info, warning, error and fatal messages.
             */
            static const int LOG_LEVEL_FATAL;
            /**
             * @brief The log level index for displaying all the messages.
             */
            static const int LOG_LEVEL_DEBUG;       
            
            /**
             * @brief Destructor.
             */
            virtual ~Logger();
            
            /**
             * @brief Logs an info message in the console with an object.
             * @param object The object of the log.
             * @param msg The message to log.
             */
            void info(std::string object, std::string msg);
            /**
             * @brief Logs an info message in the console with the object "Quick Info".
             * @param msg The message to log.
             */
            void info(std::string msg);
            
            /**
             * @brief Logs a warning message in the console with an object.
             * @param object The object of the log.
             * @param msg The message to log.
             */
            void warn(std::string object, std::string msg);
            /**
             * @brief Logs a warning message in the console with the object "Quick Warning".
             * @param msg The message to log.
             */
            void warn(std::string msg);
            
            /**
             * @brief Logs an error message in the console with an object.
             * @param object The object of the log.
             * @param msg The message to log.
             */
            void error(std::string object, std::string msg);
            /**
             * @brief Logs an error message in the console with the object "Quick Error".
             * @param msg The message to log.
             */
            void error(std::string msg);
            
            /**
             * @brief Logs a fatal error message in the console with an object.
             * @param object The object of the log.
             * @param msg The message to log.
             */
            void fatal(std::string object, std::string msg);
            /**
             * @brief Logs a fatal error message in the console with the object "Quick Fatal".
             * @param msg The message to log.
             */
            void fatal(std::string msg);
            
            /**
             * @brief Logs a debug message in the console with an object.
             * @param object The object of the log.
             * @param msg The message to log.
             */
            void debug(std::string object, std::string msg);
            /**
             * @brief Logs a debug message in the console with the object "Quick Debug".
             * @param msg The message to log.
             */
            void debug(std::string msg);
            
            /**
             * @brief Sets the logger level to filter the messages.
             */
            void setLevel(int level);
            
            /**
             * @brief The method to get the unique instance of Logger.
             * @return The unique logger instance.
             */
            static Logger* get();
            
            /**
             * @brief OpenGL Debug message callback.
             * @param source The source of the message.
             * @param type The type of the message.
             * @param id The id of the message.
             * @param severity The severity of the message.
             * @param length The length of the message.
             * @param message The message itself.
             * @param userParam The user parameter for the callback.
             */
            static void GLAPIENTRY GLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
            
        private:
            int level = LOG_LEVEL_FATAL;
            
            static Logger* instance;
            
            Logger();
        };
    }
}

#endif /* LOGGER_H */


#include "Logger.h"

#include <iostream>

using namespace light2d::core;

Logger* Logger::instance = nullptr;

const int Logger::LOG_LEVEL_INFO = 0;
const int Logger::LOG_LEVEL_WARNING = 1;
const int Logger::LOG_LEVEL_ERROR = 2;
const int Logger::LOG_LEVEL_FATAL = 3;
const int Logger::LOG_LEVEL_DEBUG = 4;

Logger* Logger::get() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    
    return instance;
}

Logger::Logger() {
}

Logger::~Logger() {
    
}

void Logger::setLevel(int level) {
    this->level = level;
}

void Logger::info(std::string object, std::string msg) {
    if (level >= LOG_LEVEL_INFO)
        std::cout << "INFO :: " << object << " :: " << msg << std::endl;
}

void Logger::info(std::string msg) {
    info("Quick Info", msg);
}

void Logger::warn(std::string object, std::string msg) {
    if (level >= LOG_LEVEL_WARNING)
        std::cout << "WARNING :: " << object << " :: " << msg << std::endl;
}

void Logger::warn(std::string msg) {
    warn("Quick Warning", msg);
}

void Logger::error(std::string object, std::string msg) {
    if (level >= LOG_LEVEL_ERROR)
        std::cout << "ERROR :: " << object << " :: " << msg << std::endl;
}

void Logger::error(std::string msg) {
    error("Quick Error", msg);
}

void Logger::fatal(std::string object, std::string msg) {
    if (level >= LOG_LEVEL_FATAL)
        std::cout << "FATAL :: " << object << " :: " << msg << std::endl;
}

void Logger::fatal(std::string msg) {
    fatal("Quick Fatal", msg);
}

void Logger::debug(std::string object, std::string msg) {
    if (level >= LOG_LEVEL_DEBUG)
        std::cout << "DEBUG :: " << object << " :: " << msg << std::endl;
}

void Logger::debug(std::string msg) {
    debug("Quick Debug", msg);
}

void GLAPIENTRY
Logger::GLErrorCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    // ignore non-significant error/warning codes
    if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return; 

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " <<  message << std::endl;

    switch (source)
    {
        case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
        case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
        case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
        case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
    } std::cout << std::endl;

    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break; 
        case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
        case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
        case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
        case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
        case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
    } std::cout << std::endl;
    
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
        case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
        case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
        case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    } std::cout << std::endl;
    std::cout << "---------------" << std::endl;
}

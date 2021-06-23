#include "Shader.h"

#include <GL/glew.h>
#include <stdexcept>
#include <glm/gtc/type_ptr.hpp>
#include <glm/fwd.hpp>

#include "../core/Logger.h"
#include "../utils/FileReader.h"

using namespace light2d::core_graphics;

Shader::Shader() {
}

Shader::~Shader() {
}


void Shader::create(const char* vertexPath, const char* fragmentPath) {
    
    std::string vertexSource = utils::FileReader::readFile(vertexPath);
    std::string fragmentSource = utils::FileReader::readFile(fragmentPath);
    
    const char* vertexSrc = vertexSource.c_str();
    const char* fragmentSrc = fragmentSource.c_str();
    
    uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    
    glShaderSource(vertexShader, 1, &vertexSrc, NULL);
    glCompileShader(vertexShader);
    {
        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            core::Logger::get()->fatal("OpenGL vertex shader", "Compilation failed : " + std::string(infoLog));
            throw std::runtime_error("Vertex shader compilation failed !");
        }
    }
    
    glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);
    glCompileShader(fragmentShader);
    
    {
        int  success;
        char infoLog[512];
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            core::Logger::get()->fatal("OpenGL fragment shader", "Compilation failed : " + std::string(infoLog));
            throw std::runtime_error("Fragment shader compilation failed !");
        }
    }
    
    program_id = glCreateProgram();
    
    glAttachShader(program_id, vertexShader);
    glAttachShader(program_id, fragmentShader);
    glLinkProgram(program_id);
    
    {
        int success;
        char infoLog[512];
        glGetProgramiv(program_id, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(program_id, 512, NULL, infoLog);
            core::Logger::get()->fatal("OpenGL shader program", "Linking failed : " + std::string(infoLog));
            throw std::runtime_error("Shader compilation failed !");
        }
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 
}

void Shader::bind() {
    glUseProgram(program_id);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::destroy() {
    glDeleteProgram(program_id);
}

void Shader::setFloat(std::string propertyName, float value) {
    int loc = checkUniformName(propertyName);
    if (loc != -1)
        glUniform1f(loc, value); 
}

void Shader::setFloat2(std::string propertyName, float* array) {
    int loc = checkUniformName(propertyName);
    if (loc != -1)
        glUniform2f(loc, array[0], array[1]); 
}

void Shader::setFloat3(std::string propertyName, float* array) {
    int loc = checkUniformName(propertyName);
    if (loc != -1)
        glUniform3f(loc, array[0], array[1], array[2]); 
}

void Shader::setFloat4(std::string propertyName, float* array) {
    int loc = checkUniformName(propertyName);
    if (loc != -1)
        glUniform4f(loc, array[0], array[1], array[2], array[3]); 
}

void Shader::setInt(std::string propertyName, int value) {
    int loc = checkUniformName(propertyName);
    if (loc != -1)
        glUniform1i(loc, value); 

}

void Shader::setBool(std::string propertyName, bool value) {
    int loc = checkUniformName(propertyName);
    if (loc != -1)
        glUniform1i(loc, (int)value); 

}

void Shader::setMatrix4(std::string propertyName, bool transpose, const float* matrix_ptr) {
    int loc = checkUniformName(propertyName);
    if (loc != -1)
        glUniformMatrix4fv(loc, 1, transpose, matrix_ptr);
}

int Shader::checkUniformName(std::string propertyName) {
    int loc = glGetUniformLocation(program_id, propertyName.c_str());
    if (loc == -1) {
        core::Logger::get()->error("Shader Property", "Can't find property : " + propertyName);
    }
    return loc;
}
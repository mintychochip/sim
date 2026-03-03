#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "shader.hpp"

ShaderLog::ShaderLog(ShaderLogType type, GLuint id) {
    GLuint log_length = 0;
    glGetProgramiv(id, GL_INFO_LOG_LENGTH, &log_length);
    if (log_length > 0) {
        _log.resize(log_length);
    }
    if (type == ShaderLogType::Shader) {
        glGetShaderiv(id, GL_COMPILE_STATUS, &_success);
        if (log_length > 0) {
            glGetShaderInfoLog(id, log_length, std::nullptr, &_log[0]);
        }
    } else {
        glGetProgramiv(id, GL_LINK_STATUS, &_success);
        if (log_length > 0) {
            glGetProgramInfoLog(id, log_length, std::nullptr, &_log[0]);
        }
    }
}

Shader::Shader(GLuint type, const std::string& source) : _id{glCreateShader(type)} {
    glShaderSource(_id, 1, &source, NULL);
    glCompileShader(_id);

    auto log = ShaderLog{ShaderLogType::Shader,_id};

}

Shader::~Shader() {
    glDeleteShader(_id); 
}

ShaderProgram::ShaderProgram(GLuint vertex, GLuint fragment) : _id{glCreateProgram()} {
    glAttachShader(_id, vertex);
    glAttachShader(_id, fragment);
    glLinkProgram(_id);
}

void ShaderProgram::use() {
    glUseProgram(_id);
}

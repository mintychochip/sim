#include "shader.hpp"

namespace shader {
    Shader::Shader(GLuint type) : _id{glCreateShader(type)} {}
    
    Shader::~Shader() { glDeleteShader(_id); }
    
    void Shader::source(const std::string& source) {
        const char* src = source.c_str();
        glShaderSource(_id, 1, &src, nullptr);
    }

    Result Shader::compile(unsigned int log_size) {
        glCompileShader(_id);
        int success;
        glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
        std::string log;
        if (!success) {
            log.resize(log_size);
            glGetShaderInfoLog(_id, log_size, nullptr, &log[0]); 
        }
        return Result {success, log};
    }

    ShaderProgram::ShaderProgram() : _id {glCreateProgram()} {}

    ShaderProgram::~ShaderProgram() { glDeleteProgram(_id); }

    void ShaderProgram::attach_shader(Shader& shader) {
        glAttachShader(_id, shader.id());
    }

    Result ShaderProgram::link(unsigned int log_size) {
        glLinkProgram(_id);
        int success;
        glGetProgramiv(_id, GL_LINK_STATUS, &success);
        std::string log;
        if (!success) {
            log.resize(log_size);
            glGetProgramInfoLog(_id, log_size, nullptr, &log[log_size]);
        }
        return Result {success, log};
    }
}

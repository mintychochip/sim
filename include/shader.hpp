#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

enum ShaderLogType {
    Shader,
    Program
};

enum class ShaderType {
    Vertex = GL_VERTEX_SHADER,
    Fragment = GL_FRAGMENT_SHADER
};

class ShaderLog {
    public:
        explicit ShaderLog(ShaderLogType type, std::size_t id);
    private:
        int _success;
        std::string _log;
};

class Shader {
    public:
        Shader(ShaderType type, const std::string& source);
        ~Shader();
        void use();
        void attach_program(ShaderProgram& program);
        unsigned int id() const {
            return _id;
        }
    private:
        unsigned int _id;
};

class ShaderProgram {
    public:
        ShaderProgram(std::size_t vertex, std::size_t fragment);
        ~ShaderProgram();
        void use();
    private:
        GLuint _id;
        
};

Shader load_shader(const std::path) {

}

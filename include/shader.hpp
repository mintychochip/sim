#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

enum ShaderLogType {
    Shader,
    Program
};

class ShaderLog {
    public:
        explicit ShaderLog(ShaderLogType type, GLuint id);
    private:
        int _success;
        std::string _log;
};

class Shader {
    public:
        GLuint _id;
        Shader(GLuint type, const std::string& source);
        ~Shader();
        void use();
};

class ShaderProgram {
    public:
        ShaderProgram(GLuint vertex, GLuint fragment);
        ~ShaderProgram();
        void use();
    private:
        GLuint _id;
        
};


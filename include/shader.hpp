#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace shader {

    struct Result {
        int success;
        std::string log;
    };

    class Shader {
        private:
            unsigned int _id;
        public:
            Shader(unsigned int type);
            ~Shader();
            void source(const std::string& source);
            Result compile(unsigned int log_size);
            unsigned int id() const { return _id; }
    };

    class ShaderProgram {
        private:
            unsigned int _id;
        public:
            ShaderProgram();
            ~ShaderProgram();
            void attach_shader(Shader& shader);
            Result link(unsigned int log_size);
            unsigned int id() const { return _id; }
    };

}

#include <iostream>
#include <cstdint>
#include "log.hpp"

ShaderCompileLog::ShaderCompileLog(GLuint shader_id, std::size_t log_length) {
    int success;
    char *log = new char[log_length];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
}

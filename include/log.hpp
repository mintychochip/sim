#pragma once
#include <iostream>
#include <cstdint>
#include <string>
class ShaderCompileLog {
    public:
        ShaderCompileLog(std::size_t log_length) = default;
        ~ShaderCompileLog() = default;
        void operator<<(std::cout);
    private:
        int success;
        std::string _log;
};

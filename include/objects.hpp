#pragma once

#include <cstddef>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum class BufferUsageType {
    Static = GL_STATIC_DRAW,
    Dynamic = GL_DYNAMIC_DRAW,
    Stream = GL_STREAM_DRAW
};

enum class AttributeType {
    Float = GL_FLOAT
};

class VertexBufferObject {
    private:
        unsigned int _id, _size;
    public:
        VertexBufferObject(unsigned int size);
        ~VertexBufferObject();
        void use();
        void update_data(const void* data, unsigned int size, BufferUsageType usage_type = BufferUsageType::Static);
};

class VertexArrayObject {
    private:
        unsigned int _id, _size;
    public:
        VertexArrayObject(unsigned int size);
        ~VertexArrayObject();
        void use();
        void attribute_pointer(unsigned int index, int size, AttributeType attribute_type, bool normalized, std::size_t stride, const void* pointer);
};

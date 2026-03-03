#include <cstddef>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vao.hpp"

VertexBufferObject::VertexBufferObject(const void* data, std::size_t size, BufferUsageType usage_type) : _size{size} {
    glGenBuffers(_size, &_id);
    glBindBuffer(GL_ARRAY_BUFFER, _id);
    glBufferData(GL_ARRAY_BUFFER, size, data, static_cast<GLenum>(usage_type));
}

void VertexBufferObject::update_data(const void* data, std::size_t size, std::size_t offset) {
    
}

void VertexBufferObject::use() {
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

VertexArrayObject::VertexArrayObject(std::size_t size) : _size{size} {
    glGenVertexArrays(size, &_id);
}

void VertexArrayObject::use() {
    glBindVertexArray(_id);
}

ElementBufferObject::ElementBufferObject(const void* data, std::size_t size, BufferUsageType usage_type) : _size{size} {
   glGenBuffers(_size, &_id);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, _size, data, static_cast<GLenum>(usage_type));
}

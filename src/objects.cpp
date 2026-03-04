#include "objects.hpp"

VertexBufferObject::VertexBufferObject(unsigned int size) : _size{size} {
    glGenBuffers(size, &_id);
}

VertexBufferObject::~VertexBufferObject() { glDeleteBuffers(_size, &_id); }

void VertexBufferObject::use() { glBindBuffer(GL_ARRAY_BUFFER, _id); }

void VertexBufferObject::update_data(const void* data, unsigned int size, BufferUsageType usage_type) {
    glBufferData(GL_ARRAY_BUFFER, size, data, static_cast<GLenum>(usage_type));
}

VertexArrayObject::VertexArrayObject(unsigned int size) : _size{size} {
    glGenVertexArrays(size, &_id);
}

VertexArrayObject::~VertexArrayObject() { glDeleteVertexArrays(_size, &_id); }

void VertexArrayObject::use() { glBindVertexArray(_id); }

void VertexArrayObject::attribute_pointer(unsigned int index, int size, AttributeType attribute_type, bool normalized, std::size_t stride, const void* pointer) {
    glVertexAttribPointer(index, size, static_cast<GLenum>(attribute_type), normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}


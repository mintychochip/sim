#include <cstddef>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum class BufferUsageType {
    Static = GL_STATIC_DRAW,
    Dynamic = GL_DYNAMIC_DRAW,
    Stream = GL_STREAM_DRAW
};

class VertexBufferObject {
    public:
        VertexBufferObject(const void* data, std::size_t size, BufferUsageType usage_type);
        void update_data(const void* data, std::size_t size, std::size_t offset = 0);
        void use();
    private:
        unsigned int _id;
        std::size_t _size;
};

class VertexArrayObject {
    public:
        VertexArrayObject(std::size_t size);
        void use();
        unsigned int id() const {
            return _id;
        }
    private:
        unsigned int _id;
        std::size_t _size;
};

class ElementBufferObject {
    public:
        ElementBufferObject(const void* data, std::size_t size, BufferUsageType usage_type);
    private:
        unsigned int _id;
        std::size_t _size;
};

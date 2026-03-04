#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include <fstream>

#include "shader.hpp"
#include "objects.hpp"

const char *vertex_shader_source = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

void handle_input(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

std::string read_string(const char* file_path) {
    std::ifstream file(file_path);
    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    auto vao = VertexArrayObject{1};
    vao.use();
    auto vbo = VertexBufferObject{1};
    vbo.use();
    vbo.update_data(vertices, sizeof(vertices));
    vao.attribute_pointer(0, 3, AttributeType::Float, false, 3 * sizeof(float), (void*) 0);
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };
    std::cout << __func__ << '\n';
    auto vertex = shader::Shader{GL_VERTEX_SHADER};
    const std::string ve_source = read_string("./shaders/vertex.glsl");
    std::cout << ve_source << std::endl;
    vertex.source(ve_source);
    auto ve_result = vertex.compile(512);
    auto fragment = shader::Shader{GL_FRAGMENT_SHADER};
    std::string frag_source = read_string("./shaders/fragment.glsl");
    fragment.source(frag_source);
    auto fr_result = fragment.compile(512);
    std::cout << fr_result.log;
    auto program = shader::ShaderProgram{};
    program.attach_shader(vertex);
    program.attach_shader(fragment);
    auto link_result = program.link(512);
    while (!glfwWindowShouldClose(window)) {
        handle_input(window);
        glUseProgram(program.id());
        vao.use();
        glDrawArrays(GL_TRIANGLES,0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

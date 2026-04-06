# Simulator

<p align="center">
  <img src="https://img.shields.io/badge/C++-17-blue?style=flat-square&logo=c%2B%2B&color=00599C" alt="C++17">
  <img src="https://img.shields.io/badge/OpenGL-3.3-green?style=flat-square&logo=opengl&color=5586A4" alt="OpenGL 3.3">
  <img src="https://img.shields.io/badge/GLFW-Windowing-orange?style=flat-square" alt="GLFW">
  <img src="https://img.shields.io/badge/GLAD-Loader-yellow?style=flat-square" alt="GLAD">
  <img src="https://img.shields.io/badge/CMake-Build-blue?style=flat-square&logo=cmake&color=064F8C" alt="CMake">
</p>

<p align="center">
  <strong>OpenGL Learning Project — Custom Graphics Engine</strong>
</p>

<p align="center">
  A minimal OpenGL simulator built from scratch for learning modern graphics programming.
</p>

---

## Features

- **Triangle Rendering** — Basic OpenGL pipeline demonstration
- **Custom Shader Classes** — C++ wrappers for shader compilation and linking
- **VBO/VAO Management** — Object-oriented vertex buffer and array handling
- **GLFW Integration** — Cross-platform window creation and input handling
- **Real-time Loop** — Game loop with buffer swapping and event polling
- **Modern OpenGL** — Core profile 3.3 with vertex attributes

---

## Tech Stack

| Component | Technology |
|-----------|------------|
| **Language** | C++17 |
| **Graphics API** | OpenGL 3.3 (Core Profile) |
| **Windowing** | GLFW 3 |
| **Loader** | GLAD |
| **Build System** | CMake 3.10+ |

---

## Quick Start

### Prerequisites

- C++17 compatible compiler (GCC, Clang, MSVC)
- CMake 3.10+
- GLFW3 installed on your system

### Build

```bash
# Clone the repository
git clone https://github.com/mintychochip/sim.git
cd sim

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build
make

# Run
./Simulator
```

### Windows (Visual Studio)

```bash
# Generate Visual Studio project
cmake .. -G "Visual Studio 17 2022"

# Open Simulator.sln and build
```

---

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    Application Flow                       │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐  │
│  │  GLFW Init  │───▶│ GLAD Loader │───▶│   Window    │  │
│  └─────────────┘    └─────────────┘    └─────────────┘  │
│                                               │         │
│                                               ▼         │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐  │
│  │   Render    │◀───│    Game     │◀───│   Shader    │  │
│  │   Loop      │    │    Loop     │    │   Program   │  │
│  └─────────────┘    └─────────────┘    └──────┬──────┘  │
│       │                                         │         │
│       │         ┌─────────────────────────┐    │         │
│       └────────▶│        VAO/VBO          │◀───┘         │
│                 │    (Vertex Arrays)     │              │
│                 └─────────────────────────┘              │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

---

## Core Components

### Shader System (`shader.hpp`)

```cpp
// Create and compile vertex shader
auto vertex = shader::Shader{GL_VERTEX_SHADER};
vertex.source(vertex_shader_code);
auto result = vertex.compile(512);

// Create shader program
auto program = shader::ShaderProgram{};
program.attach_shader(vertex);
program.attach_shader(fragment);
program.link(512);

// Use in render loop
glUseProgram(program.id());
```

### Vertex Buffer Object (`objects.hpp`)

```cpp
// Create VAO and VBO
auto vao = VertexArrayObject{1};
vao.use();

auto vbo = VertexBufferObject{1};
vbo.use();
vbo.update_data(vertices, sizeof(vertices));

// Configure vertex attributes
vao.attribute_pointer(
    0,                    // Location
    3,                    // Size (vec3)
    AttributeType::Float, // Type
    false,                // Normalized
    3 * sizeof(float),    // Stride
    (void*) 0             // Offset
);
```

---

## Project Structure

```
sim/
├── CMakeLists.txt          # CMake build configuration
├── src/
│   ├── main.cpp           # Entry point and render loop
│   ├── glad.c             # OpenGL loader implementation
│   └── *.cpp              # Implementation files
├── include/
│   ├── shader.hpp         # Shader wrapper classes
│   ├── objects.hpp        # VBO/VAO wrapper classes
│   └── glad/
│       └── glad.h         # GLAD header
├── shaders/
│   ├── vertex.glsl        # Vertex shader source
│   └── fragment.glsl      # Fragment shader source
└── build/                 # Build output (generated)
```

---

## Learning Goals

This project demonstrates:

1. **Modern OpenGL Pipeline** — VAOs, VBOs, shaders (no immediate mode)
2. **C++ RAII** — Automatic resource management for GL objects
3. **Shader Abstraction** — Object-oriented shader compilation
4. **Build Systems** — CMake configuration for graphics projects
5. **Cross-Platform** — GLFW for Windows, macOS, Linux support

---

## Customization

### Adding New Shaders

1. Create `.glsl` files in `shaders/`
2. Load in `main.cpp`:
   ```cpp
   std::string source = read_string("./shaders/myshader.glsl");
   ```
3. Compile and link as shown in the examples

### Extending VBO/VAO

The wrapper classes support:
- Dynamic buffer updates
- Multiple attribute pointers
- Different buffer usage types (`Static`, `Dynamic`, `Stream`)

---

## Contributing

This is a learning project, but improvements welcome!

1. Fork the repository
2. Add features (textures, camera, more shapes)
3. Submit a Pull Request

---

## License

MIT License

---

<p align="center">
  Learning OpenGL, one triangle at a time
</p>

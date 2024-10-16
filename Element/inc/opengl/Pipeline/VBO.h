#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include <glm/glm.hpp>

struct Vertex
{
    glm::vec3 pos;
    glm::vec3 col;
};

struct Geometry
{
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
};

struct VBO
{
    uint32_t handle;
};

void vbo_create(VBO& self);
void vbo_bind(VBO& self);
void vbo_buffer(VBO& self, std::vector<Vertex> vertices);
void vbo_update_buffer(VBO& self, std::vector<Vertex> vertices);
void vbo_unbind(VBO& self);
void vbo_delete(VBO& self);
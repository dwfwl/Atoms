#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

struct VAO
{
    uint32_t handle;
};

void vao_create(VAO& self);
void vao_bind(VAO& self);
void vao_attr(VAO& self, int index, uint32_t size, GLenum type, GLsizei stride, size_t offset);
void vao_unbind(VAO& self);
void vao_delete(VAO& self);
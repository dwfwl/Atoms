#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>

struct EBO
{
    uint32_t handle;
};

void ebo_create(EBO& self);
void ebo_bind(const EBO& self);
void ebo_buffer(const EBO& self, std::vector<uint32_t> indices);
void ebo_unbind(const EBO& self);
void ebo_delete(EBO& self);
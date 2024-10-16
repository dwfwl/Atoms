#pragma once
#include <iostream>
#include <fstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <string>

std::string read(const char* _file);
void cerr(unsigned int shader, const char* type);

struct Shader
{
    unsigned int handle;
};

void shader_create(Shader* self, const char* vert, const char* frag);
void shader_use(Shader* self);
void shader_delete(Shader* self);
void u_mat4f(std::unique_ptr<Shader>& shader, const char* name, glm::mat4 matrix);
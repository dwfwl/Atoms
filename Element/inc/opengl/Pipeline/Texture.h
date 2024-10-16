#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stb/stb_image.h>
#include <memory>
#include <string>

struct Texture
{
    unsigned int handle;
    unsigned char* data;
    std::string type;
};

bool texture_create(Texture& self, const char* file);
void texture_bind(Texture& self);
void texture_unbind(Texture& self);
void texture_delete(Texture& self);
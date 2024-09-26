#pragma once
#include <iostream>
#include <fstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <memory>

inline std::string read(const char* _file)
{
	std::ifstream in(_file, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

inline void cerr(unsigned int shader, const char* type)
{
	int compiled;

	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}

struct Shader
{
	unsigned int handle;
};

inline void shader_create(Shader* self, const char* vert, const char* frag)
{
	std::string vertexCode = read(vert);
	std::string fragmentCode = read(frag);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	cerr(vertexShader, "VERTEX");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	cerr(fragmentShader, "FRAGMENT");

	self->handle = glCreateProgram();
	glAttachShader(self->handle, vertexShader);
	glAttachShader(self->handle, fragmentShader);
	glLinkProgram(self->handle);
	cerr(self->handle, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

inline void shader_use(Shader* self)
{
	glUseProgram(self->handle);
}

inline void shader_delete(Shader* self)
{
	glDeleteProgram(self->handle);
}

inline void u_mat4f(std::unique_ptr<Shader>& shader, const char* name, glm::mat4 matrix)
{
	shader_use(shader.get());
	GLint loc = glGetUniformLocation(shader->handle, name);
	if (loc == -1)
	{
		std::cerr << "Uniform not found or not used" << std::endl;
	}
	else
	{
		glUniformMatrix4fv(loc, 1, GL_FALSE, &matrix[0][0]);
	}
}
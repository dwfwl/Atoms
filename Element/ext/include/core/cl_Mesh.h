#pragma once
#include <glad/glad.h>

#include <VAO.h>
#include <VBO.h>
#include <EBO.h>
#include <Texture.h>

class Mesh
{
public:
	Mesh(std::vector<Vertex> vert, std::vector<uint32_t> ind);
	~Mesh();

	void draw()
	{
		vao_bind(vao);
		glDrawElements(GL_TRIANGLES, indices.size() * sizeof(int), GL_UNSIGNED_INT, 0);
	}
	
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

private:
	VAO vao;
	VBO vbo;
	EBO ebo;
};

Mesh::Mesh(std::vector<Vertex> vert, std::vector<uint32_t> ind)
{
	vertices = vert;
	indices = ind;

	vao_create(vao);
	vbo_create(vbo);
	ebo_create(ebo);

	vao_bind(vao);
	vbo_buffer(vbo, vertices);
	ebo_buffer(ebo, indices);

	vao_attr(vao, 0, 3, GL_FLOAT, sizeof(Vertex), 0);
	vao_attr(vao, 1, 2, GL_FLOAT, sizeof(Vertex), (3 * sizeof(float)));
	vao_attr(vao, 2, 1, GL_FLOAT, sizeof(Vertex), (5 * sizeof(float)));
}

Mesh::~Mesh()
{
	vao_delete(vao);
	vbo_delete(vbo);
	ebo_delete(ebo);
}
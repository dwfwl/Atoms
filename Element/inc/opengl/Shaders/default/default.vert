#version 330 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 col;

out vec4 vertexColor;

uniform mat4 proj;

void main()
{
	gl_Position = proj * vec4(pos, 1.0f);
	vertexColor = vec4(col, 1.0f);
}
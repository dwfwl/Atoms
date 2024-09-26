#include <string>
#include <functional>
#include <cmath>
#include <sstream>
#include <iomanip>

#include <opengl/Pipeline/VAO.h>
#include <opengl/Pipeline/VBO.h>
#include <opengl/Pipeline/EBO.h>

#include <text/text.h>

struct Element
{
	Element(std::string symbol, int atNo, float mass) {
		m_Symbol = symbol;
		m_AtNo = atNo;
		m_Mass = mass;
		m_Electrons = atNo;
		m_Neutrons = std::round(m_Mass - m_AtNo);
	}

	std::string m_Symbol;

	int m_AtNo;
	int m_Neutrons;
	int m_Electrons;
	float m_Mass;
};

class ElementUi
{
public:
	ElementUi() = default;
	ElementUi(Element& element, Geometry&& geometry);
	~ElementUi();

	Element* m_Element;

	void buffers()
	{
		vao_create(vao);
		vbo_create(vbo);
		ebo_create(ebo);

		vao_bind(vao);
		vbo_buffer(vbo, m_Geometry.vertices);
		ebo_buffer(ebo, m_Geometry.indices);

		vao_attr(vao, 0, 3, GL_FLOAT, sizeof(Vertex), offsetof(Vertex, pos));
		vao_attr(vao, 1, 3, GL_FLOAT, sizeof(Vertex), offsetof(Vertex, col));

		m_Stream << std::fixed << std::setprecision(2) << std::round(m_Element->m_Mass * 100) / 100;
	}
	void update();
	void draw();

	std::stringstream m_Stream;

	Geometry m_Geometry;

	VAO vao;
	VBO vbo;
	EBO ebo;

	Text textUI;
};
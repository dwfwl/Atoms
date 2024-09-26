#include <element.h>
#include <fstream>

ElementUi::ElementUi(Element& element, Geometry&& geometry)
	: m_Geometry(geometry)
{
	m_Element = new Element(element);
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

ElementUi::~ElementUi()
{
	delete m_Element;
}

void ElementUi::update()
{
	vbo_update_buffer(vbo, m_Geometry.vertices);
}

glm::vec3 findMidpoint(const std::vector<Vertex>& vertices) {
	glm::vec3 midpoint(0.0f, 0.0f, 0.0f);

	for (auto& vertex : vertices) {
		midpoint += vertex.pos;
	}

	if (!vertices.empty())
	{
		midpoint /= static_cast<float>(vertices.size());
	}
	else
	{
		std::cout << "Vertices is empty" << std::endl;
	}

	return midpoint;
}

glm::vec2 openglToGlfw(glm::vec3 openglCoords, int width, int height) {
	glm::vec2 xc(-1.83673, 1.83673f);

	float x = ((openglCoords.x - xc.x) / (xc.y - xc.x)) * width;
	float y = (-1.0f - openglCoords.y) / (-1.0f - 1.0f) * height;

	return glm::vec2(x, y);
}


void ElementUi::draw()
{
	vao_bind(vao);
	glDrawElements(GL_LINE_STRIP, m_Geometry.indices.size(), GL_UNSIGNED_INT, 0);
	

	GLenum err;
	if ((err = glGetError()) != GL_NO_ERROR)
	{
		std::cout << err << std::endl;
	}


	if (m_Geometry.vertices.empty())
	{
		// std::cout << "Vertices vector is empty" << std::endl;
		return;
	}
	glm::vec3 midpoint = findMidpoint(m_Geometry.vertices);
	glm::vec2 pixel = openglToGlfw(glm::vec3(midpoint.x, midpoint.y, 0.0f), 1800, 980);

	if (m_Element->m_Symbol.size() >= 2)
	{		
		if (m_Element->m_AtNo == 3)
		{
			textUI.Draw(std::to_string(m_Element->m_AtNo), pixel.x - 36, pixel.y + 20, 0.4f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Element->m_Symbol, pixel.x - 20, pixel.y - 15, 0.85f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Stream.str(), pixel.x - 13, pixel.y - 33, 0.25f, glm::vec3(1.0f, 1.0f, 1.0f));
		}
		else if (m_Element->m_AtNo == 77)
		{
			textUI.Draw(std::to_string(m_Element->m_AtNo), pixel.x - 36, pixel.y + 20, 0.4f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Element->m_Symbol, pixel.x - 15, pixel.y - 15, 0.85f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Stream.str(), pixel.x - 17, pixel.y - 33, 0.25f, glm::vec3(1.0f, 1.0f, 1.0f));
		} else
		{
			textUI.Draw(std::to_string(m_Element->m_AtNo), pixel.x - 36, pixel.y + 20, 0.4f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Element->m_Symbol, pixel.x - 25.5, pixel.y - 15, 0.85f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Stream.str(), pixel.x - 17, pixel.y - 33, 0.25f, glm::vec3(1.0f, 1.0f, 1.0f));
		}
	}
	else
	{
		if (m_Element->m_AtNo == 53)
		{
			textUI.Draw(std::to_string(m_Element->m_AtNo), pixel.x - 36, pixel.y + 20, 0.4f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Element->m_Symbol, pixel.x - 10, pixel.y - 18, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Stream.str(), pixel.x - 20, pixel.y - 33, 0.28f, glm::vec3(1.0f, 1.0f, 1.0f));
		}
		else if (m_Element->m_AtNo == 74)
		{
			textUI.Draw(std::to_string(m_Element->m_AtNo), pixel.x - 36, pixel.y + 20, 0.4f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Element->m_Symbol, pixel.x - 22, pixel.y - 14, 0.85f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Stream.str(), pixel.x - 20, pixel.y - 33, 0.28f, glm::vec3(1.0f, 1.0f, 1.0f));
		}
		else
		{
			textUI.Draw(std::to_string(m_Element->m_AtNo), pixel.x - 36, pixel.y + 20, 0.4f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Element->m_Symbol, pixel.x - 20, pixel.y - 18, 0.95f, glm::vec3(1.0f, 1.0f, 1.0f));
			textUI.Draw(m_Stream.str(), pixel.x - 17, pixel.y - 33, 0.28f, glm::vec3(1.0f, 1.0f, 1.0f));
		}
	}
}
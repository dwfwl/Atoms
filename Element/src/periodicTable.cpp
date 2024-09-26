#include <periodicTable.h>

PeriodicTable::PeriodicTable()
{
	int i = 0;
	int deltaRow = 0;
	int currentRow = 3;
	for (auto& element : m_Elements)
	{
		if (deltaRow == 18)
		{
			deltaRow = 0;
			currentRow++;
		}

		if (i < 2) // row 1
		{
			int c = i;
			if (i == 1)
			{
				c += 16;
			}
			Geometry offsetGeometry = addOffset(c * 0.18f, rows[0]);
			m_ElementsUi[i].m_Element  = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();

		} else if (i >= 2 && i < 10) // row 2
		{
			int c = i;
			if (c >= 4)
			{
				c += 10;
			}
			Geometry offsetGeometry = addOffset((c-2) * 0.18f, rows[1]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();
		}
		else if (i >= 10 && i <= 17) // row 3
		{
			int c = i;
			if (c >= 12)
			{
				c += 10;
			}
			Geometry offsetGeometry = addOffset((c-10) * 0.18f, rows[2]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();
		}
		else if (i >= 18 && i <= 53) // row 4
		{
			Geometry offsetGeometry = addOffset((i - (18 * (currentRow - 2))) * 0.18f, rows[currentRow]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();

			deltaRow++;
		}
		else if (i >= 54 && i <= 55)
		{
			Geometry offsetGeometry = addOffset((i - (18 * (currentRow - 2))) * 0.18f, rows[currentRow]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();

			deltaRow++;
		}
		else if (i >= 56 && i <= 70)
		{
			Geometry offsetGeometry = addOffset(((i - 8) - (16 * (currentRow - 2))) * 0.18f, rows[7]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();
		}
		else if (i >= 71 && i <= 85)
		{
			Geometry offsetGeometry = addOffset(((i - 14) - (18 * (currentRow - 2))) * 0.18f, rows[currentRow]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();
			if (i == 85)
			{
				deltaRow = 0;
				currentRow += 1;
			}
		}
		else if (i >= 86 && i <= 87)
		{
			Geometry offsetGeometry = addOffset(((i - 14) - (18 * (currentRow - 2))) * 0.18f, rows[currentRow]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();

			deltaRow++;
		}
		else if (i >= 88 && i <= 102)
		{
			Geometry offsetGeometry = addOffset(((i - 24) - (16 * (currentRow - 2))) * 0.18f, rows[8]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();
		}
		else if (i >= 103)
		{
			Geometry offsetGeometry = addOffset(((i - 28) - (18 * (currentRow - 2))) * 0.18f, rows[currentRow]);
			m_ElementsUi[i].m_Element = new Element(element);
			m_ElementsUi[i].m_Geometry = offsetGeometry;
			m_ElementsUi[i].buffers();
		}
		i++;
	}
}

Geometry PeriodicTable::addOffset(float xOffset, Geometry& row)
{
	Geometry result = row;
	for (auto& vertex : result.vertices)
	{
		vertex.pos += glm::vec3(xOffset, 0, 0);
	}

	return result;
}
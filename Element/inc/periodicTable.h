#include "element.h"
#include <array>
#include <opengl/Shaders/shader.h>

class PeriodicTable
{
public:
	PeriodicTable();

    std::vector<Geometry> rows =
    {
        Geometry
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.66827f, 0.95f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.66827f, 0.78f ,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.78f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.95f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // row 1
        Geometry
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.66827f, 0.77, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.66827f, 0.6, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.6, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.77, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // row 2
        Geometry
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.66827f, 0.59f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.66827f, 0.42f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.42f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.59f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // row 3
        Geometry
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.66827f,  0.41f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.66827f,	 0.24f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.24f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.41f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // row 4
        Geometry
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.66827f,  0.23f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.66827f,	 0.06f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.06f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, 0.23f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // row 5
        Geometry
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.66827f,   0.05f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.66827f,	 -0.12f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, -0.12f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f,  0.05f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // row 6
        Geometry
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.66827f,  -0.13f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.66827f,	 -0.3f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, -0.3f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.49827f, -0.13f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // row 7
        Geometry   
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.30827f,  -0.36f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.30827f,	 -0.54,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.13827, -0.54f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.13827, -0.36f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // bottom row 1 
        Geometry   
        {
            std::vector<Vertex>{
                Vertex{glm::vec3(-1.30827f, -0.55f, 0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.30827f, -0.72f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.13827f, -0.72f,  0.0f), glm::vec3(1.0f)},
                Vertex{glm::vec3(-1.13827f, -0.55f, 0.0f), glm::vec3(1.0f)}
            }, std::vector<uint32_t>
            {
                0, 1,
                1, 2,
                2, 3,
                3, 0
            }
        }, // bottom row 2
    };

    void draw(Shader& shader)
    {
        int i = 0;
        for (auto& elementUi : m_ElementsUi)
        {
            shader_use(&shader);

            elementUi.draw();
            i++;
        }
    }
	Geometry addOffset(float yOffset, Geometry& placeHolder);
private:
    std::array<Element, 118> m_Elements =
    {
        Element("H",  1, 1.008),
        Element("He", 2, 4.003),
        Element("Li", 3, 6.94),
        Element("Be", 4, 9.012),
        Element("B",  5, 10.81),
        Element("C",  6, 12.011),
        Element("N",  7, 14.007),
        Element("O",  8, 15.999),
        Element("F",  9, 18.998),
        Element("Ne", 10, 20.179),
        Element("Na", 11, 22.990),
        Element("Mg", 12, 24.305),
        Element("Al", 13, 26.982),
        Element("Si", 14, 28.085),
        Element("P",  15, 30.974),
        Element("S",  16, 32.06),
        Element("Cl", 17, 35.45),
        Element("Ar", 18, 39.948),
        Element("K",  19, 39.098),
        Element("Ca", 20, 40.078),
        Element("Sc", 21, 44.956),
        Element("Ti", 22, 47.867),
        Element("V",  23, 50.942),
        Element("Cr", 24, 51.996),
        Element("Mn", 25, 54.938),
        Element("Fe", 26, 55.845),
        Element("Co", 27, 58.933),
        Element("Ni", 28, 58.693),
        Element("Cu", 29, 63.546),
        Element("Zn", 30, 65.38),
        Element("Ga", 31, 69.723),
        Element("Ge", 32, 72.63),
        Element("As", 33, 74.922),
        Element("Se", 34, 78.971),
        Element("Br", 35, 79.904),
        Element("Kr", 36, 83.798),
        Element("Rb", 37, 85.468),
        Element("Sr", 38, 87.62),
        Element("Y",  39, 88.906),
        Element("Zr", 40, 91.224),
        Element("Nb", 41, 92.906),
        Element("Mo", 42, 95.95),
        Element("Tc", 43, 98.0),
        Element("Ru", 44, 101.07),
        Element("Rh", 45, 102.91),
        Element("Pd", 46, 106.42),
        Element("Ag", 47, 107.87),
        Element("Cd", 48, 112.41),
        Element("In", 49, 114.82),
        Element("Sn", 50, 118.71),
        Element("Sb", 51, 121.76),
        Element("Te", 52, 127.60),
        Element("I",  53, 126.90),
        Element("Xe", 54, 131.29),
        Element("Cs", 55, 132.91),
        Element("Ba", 56, 137.33),
        Element("La", 57, 138.91),
        Element("Ce", 58, 140.12),
        Element("Pr", 59, 140.91),
        Element("Nd", 60, 144.24),
        Element("Pm", 61, 145.0),
        Element("Sm", 62, 150.36),
        Element("Eu", 63, 151.96),
        Element("Gd", 64, 157.25),
        Element("Tb", 65, 158.93),
        Element("Dy", 66, 162.50),
        Element("Ho", 67, 164.93),
        Element("Er", 68, 167.26),
        Element("Tm", 69, 168.93),
        Element("Yb", 70, 173.04),
        Element("Lu", 71, 174.97),
        Element("Hf", 72, 178.49),
        Element("Ta", 73, 180.95),
        Element("W",  74, 183.84),
        Element("Re", 75, 186.21),
        Element("Os", 76, 190.23),
        Element("Ir", 77, 192.22),
        Element("Pt", 78, 195.08),
        Element("Au", 79, 196.97),
        Element("Hg", 80, 200.59),
        Element("Tl", 81, 204.38),
        Element("Pb", 82, 207.2),
        Element("Bi", 83, 208.98),
        Element("Po", 84, 209),
        Element("At", 85, 210),
        Element("Rn", 86, 222),
        Element("Fr", 87, 223),
        Element("Ra", 88, 226),
        Element("Ac", 89, 227),
        Element("Th", 90, 232.04),
        Element("Pa", 91, 231.04),
        Element("U",  92, 238.03),
        Element("Np", 93, 237),
        Element("Pu", 94, 244),
        Element("Am", 95, 243),
        Element("Cm", 96, 247),
        Element("Bk", 97, 247),
        Element("Cf", 98, 251),
        Element("Es", 99, 252),
        Element("Fm", 100, 257),
        Element("Md", 101, 258),
        Element("No", 102, 259),
        Element("Lr", 103, 262),
        Element("Rf", 104, 267),
        Element("Db", 105, 270),
        Element("Sg", 106, 271),
        Element("Bh", 107, 270),
        Element("Hs", 108, 277),
        Element("Mt", 109, 278),
        Element("Ds", 110, 281),
        Element("Rg", 111, 282),
        Element("Cn", 112, 285),
        Element("Nh", 113, 286),
        Element("Fl", 114, 289),
        Element("Mc", 115, 290),
        Element("Lv", 116, 293),
        Element("Ts", 117, 294),
        Element("Og", 118, 294)
    };
	std::array<ElementUi, 118> m_ElementsUi;
};
#include <opengl/Shaders/shader.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H  

struct Character {
    unsigned int TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    unsigned int Advance;
};

class Text
{
public:
    Text();
    void Draw(const std::string& text, float x, float y, float scale, glm::vec3 color);

private:
    FT_Library ft;
    FT_Face face;
    uint32_t vao;
    uint32_t vbo;
    Shader shader;

private:
    std::map<char, Character> Characters;

private:
    void Clean();
};
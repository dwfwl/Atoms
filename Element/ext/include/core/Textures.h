#include <Texture.h>
#include <glad/glad.h>

class Textures
{
public:
	Texture Brick;
	Texture Snow;
	Textures()
	{
		glActiveTexture(GL_TEXTURE0);
		texture_create(Brick, "Assets/Textures/brick.jpg");
		glActiveTexture(GL_TEXTURE0 + 1);
		texture_create(Snow, "Assets/Textures/snow.jpg");
	}
};
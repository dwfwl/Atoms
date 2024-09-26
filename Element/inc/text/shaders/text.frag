#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D text;      // The glyph texture (grayscale)
uniform vec3 textColor;      // The color for the text

void main()
{    
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);  // Get the alpha value from the texture
    color = vec4(textColor, 1.0) * sampled;  // Apply text color
}

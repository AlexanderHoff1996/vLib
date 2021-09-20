#include "Texture.h"

//=============================================================================
vGFX::Texture::Texture()
{
	// You must activate (use) the shader to use it!
	shader.use();

	setVertexData();
	setupMatrices();
	setBuffers();
	setAttributes();
}

vGFX::Texture::~Texture()
{
	free();
}

//=============================================================================
void vGFX::Texture::createTexture(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h,
	int imageWidth, int imageHeight, const void* data, int format,
	int textureFilterMin, int textureFilterMag, int textureWrapX, int textureWrapY)
{
	x = xPos;
	y = yPos;
	width = w;
	height = h;

	// 0 = RGB, 1 = RGBA
	format = (format <= 0 ? GL_RGB : GL_RGBA);

	// You must activate (use) the shader to use it!
	shader.use();

	setVertexData();
	setupMatrices();
	setBuffers();
	setAttributes();

	// Generate the texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilterMag);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrapX);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrapY);
	glTexImage2D(GL_TEXTURE_2D, 0, format, static_cast<GLsizei>(imageWidth),
		static_cast<GLsizei>(imageHeight), 0, format, GL_UNSIGNED_BYTE, data);
}

//=============================================================================
void vGFX::Texture::render()
{
	glBindTexture(GL_TEXTURE_2D, texture);

	shader.use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

//=============================================================================
void vGFX::Texture::setVertexData()
{
	// Top left	(0)					// Top right (1)
	vertexData[0] = x;				vertexData[4] = x + width;
	vertexData[1] = y;				vertexData[5] = y;
	vertexData[2] = 0.0f;			vertexData[6] = 1.0f;
	vertexData[3] = 1.0f;			vertexData[7] = 1.0f;

	// Bottom left (3)				// Bottom right (2)
	vertexData[12] = x;				vertexData[8] = x + width;
	vertexData[13] = y + height;	vertexData[9] = y + height;
	vertexData[14] = 0.0f;			vertexData[10] = 1.0f;
	vertexData[15] = 0.0f;			vertexData[11] = 0.0f;

	// First triangle	// Second triangle
	indices[0] = 0;		indices[3] = 0;
	indices[1] = 1;		indices[4] = 3;
	indices[2] = 2;		indices[5] = 2;
}

//=============================================================================
void vGFX::Texture::setupMatrices()
{
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);

	// Set the projection matrix
	projection = glm::ortho(Viewport::getX(), Viewport::getWidth(),
		Viewport::getHeight(), Viewport::getY(), -1.0f, 1.0f);

	// Set the matrices in the vertex shader
	shader.setMat4("projection", projection);
	shader.setMat4("model", model);
}

//=============================================================================
void vGFX::Texture::setBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

//=============================================================================
void vGFX::Texture::setAttributes()
{
	// Position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
		4 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	// Texture coordinates
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
		4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
}

//=============================================================================
void vGFX::Texture::free()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

//=============================================================================
void vGFX::Texture::updateData()
{
	free();
	setVertexData();
	setBuffers();
	setAttributes();
}

//=============================================================================
void vGFX::Texture::set(float xPos, float yPos, float w, float h)
{
	x = static_cast<GLfloat>(xPos);
	y = static_cast<GLfloat>(yPos);

	width = static_cast<GLfloat>(w);
	height = static_cast<GLfloat>(h);

	updateData();
}

//=============================================================================
void vGFX::Texture::setX(float xPos)
{
	x = static_cast<GLfloat>(xPos);
	updateData();
}

void vGFX::Texture::setY(float yPos)
{
	y = static_cast<GLfloat>(yPos);
	updateData();
}

void vGFX::Texture::setWidth(float w)
{
	width = static_cast<GLfloat>(w);
	updateData();
}

void vGFX::Texture::setHeight(float h)
{
	height = static_cast<GLfloat>(h);
	updateData();
}

void vGFX::Texture::setColor(color::ColorFA col)
{
	color = col;
	updateData();
}

void vGFX::Texture::setColor(color::ColorRGBA col)
{
	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = col.a / 255.f;
	updateData();
}

void vGFX::Texture::setColor(color::ColorRGB col)
{
	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = 1.0f;
	updateData();
}
#include "Rectangle.h"

//=============================================================================
vGFX::Rectangle::Rectangle()
{
	// You must activate (use) the shader to use it!
	shader.use();

	setVertexData();
	setMatrices();
	setBuffers();
	setAttributes();
}

vGFX::Rectangle::Rectangle(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h,
	color::ColorFA col)
{
	x = xPos;
	y = yPos;
	width  = w;
	height = h;

	color = col;

	// You must activate (use) the shader to use it!
	shader.use();

	setVertexData();
	setMatrices();
	setBuffers();
	setAttributes();
}

vGFX::Rectangle::Rectangle(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h,
	color::ColorRGBA col)
{
	x = xPos;
	y = yPos;
	width  = w;
	height = h;

	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = col.a / 255.f;

	// You must activate (use) the shader to use it!
	shader.use();

	setVertexData();
	setMatrices();
	setBuffers();
	setAttributes();
}

vGFX::Rectangle::Rectangle(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h,
	color::ColorRGB col)
{
	x = xPos;
	y = yPos;
	width  = w;
	height = h;

	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = 1.0f;

	// You must activate (use) the shader to use it!
	shader.use();

	setVertexData();
	setMatrices();
	setBuffers();
	setAttributes();
}

//=============================================================================
vGFX::Rectangle::~Rectangle()
{
	free();
}

//=============================================================================
void vGFX::Rectangle::render()
{
	shader.use();
	setMatrices();

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

//=============================================================================
void vGFX::Rectangle::setVertexData()
{
	// Top left	(0)					// Top right (1)
	vertexData[0] = x;				vertexData[6] = x + width;
	vertexData[1] = y;				vertexData[7] = y;
	vertexData[2] = color.r;		vertexData[8] = color.r;
	vertexData[3] = color.g;		vertexData[9] = color.g;
	vertexData[4] = color.b;		vertexData[10] = color.b;
	vertexData[5] = color.a;		vertexData[11] = color.a;

	// Bottom left (3)				// Bottom right (2)
	vertexData[18] = x;				vertexData[12] = x + width;
	vertexData[19] = y + height;	vertexData[13] = y + height;
	vertexData[20] = color.r;		vertexData[14] = color.r;
	vertexData[21] = color.g;		vertexData[15] = color.g;
	vertexData[22] = color.b;		vertexData[16] = color.b;
	vertexData[23] = color.a;		vertexData[17] = color.a;

	// First triangle	// Second triangle
	indices[0] = 0;		indices[3] = 0;
	indices[1] = 1;		indices[4] = 3;
	indices[2] = 2;		indices[5] = 2;
}

//=============================================================================
void vGFX::Rectangle::setMatrices()
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
void vGFX::Rectangle::setBuffers()
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
void vGFX::Rectangle::setAttributes()
{
	// Position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
		6 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	// Color
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		6 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
}

//=============================================================================
void vGFX::Rectangle::free()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

//=============================================================================
void vGFX::Rectangle::updateData()
{
	free();
	setVertexData();
	setBuffers();
	setAttributes();
}

//=============================================================================
float vGFX::Rectangle::getX()				{return static_cast<float>(x);}
float vGFX::Rectangle::getY()				{return static_cast<float>(y);}
float vGFX::Rectangle::getWidth()			{return static_cast<float>(width);}
float vGFX::Rectangle::getHeight()			{return static_cast<float>(height);}

vGFX::color::ColorFA vGFX::Rectangle::getColorFA()
{
	return color;
}

vGFX::color::ColorRGBA vGFX::Rectangle::getColorRGBA()
{
	color::ColorRGBA col;
	col.r = static_cast<GLuint>(std::round(color.r * 255));
	col.g = static_cast<GLuint>(std::round(color.g * 255));
	col.b = static_cast<GLuint>(std::round(color.b * 255));
	col.a = static_cast<GLuint>(std::round(color.a * 255));

	return col;
}

vGFX::color::ColorRGB vGFX::Rectangle::getColorRGB()
{
	color::ColorRGB col;
	col.r = static_cast<GLuint>(std::round(color.r * 255));
	col.g = static_cast<GLuint>(std::round(color.g * 255));
	col.b = static_cast<GLuint>(std::round(color.b * 255));

	return col;
}

//=============================================================================
void vGFX::Rectangle::set(float xPos, float yPos, float w, float h, 
	color::ColorFA col)
{
	x = static_cast<GLfloat>(xPos);
	y = static_cast<GLfloat>(yPos);
	
	width = static_cast<GLfloat>(w);
	height = static_cast<GLfloat>(h);
	
	color = col;
	
	updateData();
}

void vGFX::Rectangle::set(float xPos, float yPos, float w, float h, 
	color::ColorRGBA col)
{
	x = static_cast<GLfloat>(xPos);
	y = static_cast<GLfloat>(yPos);

	width = static_cast<GLfloat>(w);
	height = static_cast<GLfloat>(h);

	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = col.a / 255.f;

	updateData();
}

void vGFX::Rectangle::set(float xPos, float yPos, float w, float h, 
	color::ColorRGB col)
{
	x = static_cast<GLfloat>(xPos);
	y = static_cast<GLfloat>(yPos);

	width = static_cast<GLfloat>(w);
	height = static_cast<GLfloat>(h);

	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = 1.0f;

	updateData();
}

//=============================================================================
void vGFX::Rectangle::setX(float xPos)
{
	x = static_cast<GLfloat>(xPos);
	updateData();
}

void vGFX::Rectangle::setY(float yPos)
{
	y = static_cast<GLfloat>(yPos);
	updateData();
}

void vGFX::Rectangle::setWidth(float w)
{
	width = static_cast<GLfloat>(w);
	updateData();
}

void vGFX::Rectangle::setHeight(float h)
{
	height = static_cast<GLfloat>(h);
	updateData();
}

void vGFX::Rectangle::setColor(color::ColorFA col)
{
	color = col;
	updateData();
}

void vGFX::Rectangle::setColor(color::ColorRGBA col)
{
	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = col.a / 255.f;
	updateData();
}

void vGFX::Rectangle::setColor(color::ColorRGB col)
{
	color.r = col.r / 255.f;
	color.g = col.g / 255.f;
	color.b = col.b / 255.f;
	color.a = 1.0f;
	updateData();
}
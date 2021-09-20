#include "Triangle.h"

//=============================================================================
vGFX::Triangle::Triangle()
	: vertexData {-0.5f, -0.5f,
				   0.5f, -0.5f,
				   0.0f,  0.5f}
{
	// VAO (Vertex Array Object) and VBO (Vertex Buffer Object)
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
}

vGFX::Triangle::Triangle(Point2D p1, Point2D p2, Point2D p3, color::ColorFA col)
	: vertexData {p1.x, p1.y,	col.r, col.g, col.b, col.a,
				  p2.x, p2.y,	col.r, col.g, col.b, col.a,
				  p3.x, p3.y,	col.r, col.g, col.b, col.a}
{
	// You must activate (use) the shader to use it!
	shader.use();

	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);

	// Set the projection matrix
	projection = glm::ortho(Viewport::getX(), Viewport::getWidth(),
		Viewport::getHeight(), Viewport::getY(), -1.0f, 1.0f);

	// Set the matrices in the vertex shader
	shader.setMat4("projection", projection);
	shader.setMat4("model", model);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

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
vGFX::Triangle::~Triangle()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

//=============================================================================
void vGFX::Triangle::render()
{
	shader.use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
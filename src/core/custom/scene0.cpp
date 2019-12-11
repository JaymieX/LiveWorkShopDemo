#include "workshop_pch.h"
#include "scene0.h"

#include <SDL.h>
#include <glad/glad.h>

float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

GLuint vao;
GLuint vbo;
GLuint ebo;
GLint shader_program;

const char* vertex_shader_source = "#version 450 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragment_shader_source = "#version 450 core\n"
"out vec4 FragColor;\n"
"uniform vec4 Color;\n"
"void main()\n"
"{\n"
"   FragColor = Color;\n"
"}\n\0";

Workshop::Scene0::Scene0(SceneSystem * system_) :
	Scene(system_)
{
}

void Workshop::Scene0::Begin()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	//Bind
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// Layout pos
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	}
	// Unbind
	glBindVertexArray(NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, NULL);

	// Shader

	// VS
	int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_source, 0);
	glCompileShader(vertex_shader);

	// FS
	int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_source, 0);
	glCompileShader(fragment_shader);

	// link shaders
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	// Delete
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

void Workshop::Scene0::Render()
{
	// Shader
	glUseProgram(shader_program);

	// Uniform in future
	GLint location = glGetUniformLocation(shader_program, "Color");
	glUniform4f(location, 1.0f, 0.f, 0.f, 1.0f);

	// Texture in future

	// Render
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, NULL);

	glUseProgram(0);
}

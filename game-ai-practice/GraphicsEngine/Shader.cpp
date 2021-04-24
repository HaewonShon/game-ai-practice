#include "Shader.h"
#include <string>
#include <stdexcept>
#include <vector>

const char* vertexShader = {
	"#version 450 core\n"
	"layout(location = 0) in vec2 position;\n"
	"uniform mat3 TRS;\n"
	"uniform mat3 NDC;\n"
	"void main()\n"
	"{\n"
	//"	gl_Position = vec4(NDC * TRS * position, 1.0);\n"
	"	gl_Position = vec4(position, 0.0, 1.0);\n"
	"}\n"
};

const char* fragmentShader = {
	"#version 450 core\n"
	"uniform vec3 color;\n"
	"void main()\n"
	"{\n"
	//"	gl_FragColor = vec4(color, 1.0);\n"
	"	gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);\n"
	"}\n"
};

void Shader::Init()
{
	shaderID = glCreateProgram();
	if (shaderID <= 0)
	{
		std::string errorMsg{"Failed to create shader program"};
		glDeleteProgram(shaderID);
		throw std::runtime_error(errorMsg);
	}

	GLint compileResult;
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	// compile shaders
	glShaderSource(vShader, 1, &vertexShader, NULL);
	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &compileResult);
	if (compileResult == GL_FALSE)
	{
		GLint logLength;
		glGetShaderiv(vShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> logError(logLength);
		glGetShaderInfoLog(vShader, logLength, &logLength, &logError[0]);
		glDeleteShader(vShader);
		glDeleteProgram(shaderID);
		throw std::runtime_error(logError.data());
	}

	glShaderSource(fShader, 1, &fragmentShader, NULL);
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &compileResult);
	if (compileResult == GL_FALSE)
	{
		GLint logLength;
		glGetShaderiv(fShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> logError(logLength);
		glGetShaderInfoLog(fShader, logLength, &logLength, &logError[0]);
		glDeleteShader(vShader);
		glDeleteShader(fShader);
		glDeleteProgram(shaderID);
		throw std::runtime_error(logError.data());
	}

	glAttachShader(shaderID, vShader);
	glAttachShader(shaderID, fShader);
	glLinkProgram(shaderID);
	glValidateProgram(shaderID);
	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

void Shader::Bind()
{
	glUseProgram(shaderID);
}

void Shader::Unbind()
{
	glUseProgram(0);
}

GLint Shader::GetUniformLocation(const GLchar* variableName)
{
	return glGetUniformLocation(shaderID, variableName);
}
#include "Shader.h"
#include <string>
#include <stdexcept>
#include <vector>

const char* vertexShader = {
	"#version 450 core\n"
	"layout(location = 0) in vec2 position;\n"

	"uniform mat3 TRS;\n"
	"uniform mat3 NDC;\n"
	"uniform vec3 color;\n"

	"out vec3 in_color;\n"

	"void main()\n"
	"{\n"
	"	in_color = color;\n"
	"	vec3 pos = NDC * TRS * vec3(position, 1.0);\n"
	"	gl_Position = vec4(pos.xy, 0.0, 1.0);\n"
	//"	gl_Position = vec4(position, 0.0, 1.0);\n"
	"}\n"
};

const char* fragmentShader = {
	"#version 450 core\n"
	"in vec3 in_color;\n"
	"void main()\n"
	"{\n"
	"	gl_FragColor = vec4(in_color, 1.0);\n"
	//"	gl_FragColor = vec4(in_color.x, 1.0, 0.0, 1.0);\n"
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

	glGetProgramiv(shaderID, GL_LINK_STATUS, &compileResult);
	if (compileResult == GL_FALSE)
	{
		GLint logLength;
		glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> logError(logLength);
		glGetProgramInfoLog(shaderID, logLength, &logLength, &logError[0]);
		glDeleteShader(vShader);
		glDeleteShader(fShader);
		glDeleteProgram(shaderID);
		throw std::runtime_error(logError.data());
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	if (GLint e = glGetError(); e != GL_NO_ERROR)
	{
		e++;
	}
}

void Shader::Bind() noexcept
{
	glUseProgram(shaderID);
}

void Shader::Unbind() noexcept
{
	glUseProgram(0);
}

void Shader::SetUniformFloat(const GLchar* variableName, float value) noexcept
{
	glUniform1f(GetUniformLocation(variableName), value);
}

void Shader::SetUniformInt(const GLchar* variableName, int value) noexcept
{
	glUniform1i(GetUniformLocation(variableName), value);
}

void Shader::SetUniformVec3(const GLchar* variableName, const vec3& value) noexcept
{
	glUniform3f(GetUniformLocation(variableName), value.x, value.y, value.z);
}

void Shader::SetUniformMat3(const GLchar* variableName, const mat3& value) noexcept
{
	glUniformMatrix3fv(GetUniformLocation(variableName), 1, GL_FALSE,
		value.element[0]);
		
}

GLint Shader::GetUniformLocation(const GLchar* variableName)
{
	GLint location = glGetUniformLocation(shaderID, variableName);
	return location;
}
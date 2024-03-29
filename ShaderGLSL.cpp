#include "ShaderGLSL.h"
#include <fstream>
#include <iostream>

using namespace MyEngine;
using namespace Renderer;

ShaderGlsl::ShaderGlsl()
{
	program = glCreateProgram();//create shader program
}

ShaderGlsl::~ShaderGlsl()
{
	//clean all shaders and program
	for (auto& x : shaders)
		glDeleteShader(x);
	if (glIsProgram(program))
		glDeleteProgram(program);
}

void ShaderGlsl::loadVertexShader(const char * filename)
{
	GLuint sh = loadShader(filename, GL_VERTEX_SHADER);
	shaders.push_back(sh);
}

void ShaderGlsl::loadFragmentShade(const char * filename)
{
	GLuint sh = loadShader(filename, GL_FRAGMENT_SHADER);
	shaders.push_back(sh);
}


void ShaderGlsl::loadGeometryShader(const char * filename)
{
	shaders.push_back(loadShader(filename, GL_GEOMETRY_SHADER));
}

void ShaderGlsl::loadConstrolTesselationShader(const char * filename)
{
	shaders.push_back(loadShader(filename, GL_TESS_CONTROL_SHADER));
}

void ShaderGlsl::loadEvaluationTesselationShader(const char * filename)
{
	shaders.push_back(loadShader(filename, GL_TESS_EVALUATION_SHADER));
}

void ShaderGlsl::attachAllShader()
{
	//attach all shaders, link to program and validate this program
	for (auto& x : shaders)
		glAttachShader(program, x);
	linkProgram();
	validateProgram();
}

std::string ShaderGlsl::readShader(const char * filename)
{
	//read shader from file
	this->filename = filename;
	std::string shadersource;
	std::ifstream file;
	file.open(filename, std::ios::binary);
	if (file.is_open())
	{
		file.seekg(0, file.end);
		shadersource.resize(file.tellg());
		file.seekg(0, file.beg);
		file.read(&shadersource[0], shadersource.size());
		file.close();
	}
	else
	{
		std::cerr << "File " << filename << " is not loaded!\n";
	}
	return shadersource;
}

void ShaderGlsl::checkShaderError(GLuint & sh)
{
	//return compilation log, when somthing is wrong
	GLint is_compiled = GL_TRUE;
	glGetShaderiv(sh, GL_COMPILE_STATUS, &is_compiled);
	if (is_compiled == GL_FALSE)
	{
		std::cout << "Shader " << filename << " is not compile!\n";
		GLint loglength{ 0 };
		glGetShaderiv(sh, GL_INFO_LOG_LENGTH, &loglength);
		std::string shaderlog;
		shaderlog.resize(loglength);
		glGetShaderInfoLog(sh, loglength, nullptr, &shaderlog[0]);
		std::cout << shaderlog << "\n";
	}
}

GLuint ShaderGlsl::loadShader(const char * filename, GLenum mode)
{
	//load, compile and get error log, when something is wrong in shader.
	//Use specific enum mode to direct shader type in creating shader function.
	std::string shcourc = readShader(filename);
	const char* shadersource = shcourc.c_str();
	GLuint sh = glCreateShader(mode);
	glShaderSource(sh, 1, &shadersource, nullptr);
	glCompileShader(sh);
	checkShaderError(sh);
	return sh;
}

void ShaderGlsl::linkProgram()
{
	//linkk program after attached all shaders
	glLinkProgram(program);
	GLint islinked;
	glGetProgramiv(program, GL_LINK_STATUS, &islinked);//check that program is linked
	if (islinked == GL_FALSE)
	{
		checkLinkedProgramError();
		return;
	}
	for (auto& x : shaders)
		glDetachShader(program, x);
}

void ShaderGlsl::checkLinkedProgramError()
{
	//return log about linking of program when something is wrong
	GLint length{ 0 };
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
	std::string text;
	text.resize(length);
	glGetProgramInfoLog(program, length, nullptr, &text[0]);
	std::cout << "Program is not linked!\n" << text << "\n";
}

void ShaderGlsl::validateProgram()
{
	//validate program with attached shaders and linked program
	glValidateProgram(program);
	checkValidateProgramError();
}

void ShaderGlsl::checkValidateProgramError()
{
	GLint status;
	glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
	if (status == GL_FALSE)
	{
		//if validate had mistakes, get log info and print to console
		std::cout << "Bad validation \n";
		GLint length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		char* info = new char[length + 1];
		glGetProgramInfoLog(program, length, nullptr, info);
		std::cout << info << std::endl;
		delete[] info;
	}
}
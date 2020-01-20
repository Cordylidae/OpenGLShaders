//#include <glad/glad.h>
//
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//
//class Shader
//{
//public:
//	GLint ID;
//
//	Shader(const GLchar* vertexSourcePath, const GLchar* fragmentSourcePath)
//	{
//		std::string vertexCode;
//		std::string fragmentCode;
//		std::ifstream vShaderFile;
//		std::ifstream fShaderFile;
//
//		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//
//		try
//		{
//			vShaderFile.open(vertexSourcePath);
//			fShaderFile.open(fragmentSourcePath);
//			std::stringstream vShaderStream, fShaderStream;
//
//			vShaderStream << vShaderFile.rdbuf();
//			fShaderStream << fShaderFile.rdbuf();
//
//			vShaderFile.close();
//			fShaderFile.close();
//
//			vertexCode = vShaderStream.str();
//			fragmentCode = fShaderStream.str();
//		}
//		catch (std::ifstream::failure e)
//		{
//			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
//		}
//		
//		const char* vShaderCode = vertexCode.c_str();
//		const char* fShaderCode = fragmentCode.c_str();
//
//		int vertex, fragment;
//
//		vertex = glCreateShader(GL_VERTEX_SHADER);
//		glShaderSource(vertex, 1, &vShaderCode, NULL);
//		glCompileShader(vertex);
//		checkCompileErrors(vertex, "VERTEX");
//
//		fragment = glCreateShader(GL_FRAGMENT_SHADER);
//		glShaderSource(fragment, 1, &fShaderCode, NULL);
//		glCompileShader(fragment);
//		checkCompileErrors(fragment, "FRAGMENT");
//
//		ID = glCreateProgram();
//		glAttachShader(ID, vertex);
//		glAttachShader(ID, fragment);
//		glLinkProgram(ID);
//		checkCompileErrors(ID, "PROGRAM");
//
//		glDeleteShader(vertex);
//		glDeleteShader(fragment);
//	}
//
//	void Use()
//	{
//		glUseProgram(ID);
//	}
//
//	void setBool(const std::string &name,bool value) const
//	{
//		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
//	}
//
//	void setInt(const std::string &name, int value) const
//	{
//		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
//	}
//
//	void setFloat(const std::string &name, float value) const
//	{
//		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
//	}
//private :
//
//	void checkCompileErrors(int shader, std::string type)
//	{
//		int success;
//		char infoLog[1024];
//		if (type != "PROGRAM")
//		{
//			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//			if(!success)
//			{
//				glGetShaderInfoLog(shader,1024,NULL,infoLog);
//				std::cout<< "Errors::SHADER_COPILATION_ERROR of type: "<< type << "\n" <<infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
//			}
//		}
//		else
//		{
//			glGetProgramiv(shader, GL_LINK_STATUS, &success);
//			if (!success)
//			{
//				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
//				std::cout << "ERROR::SHADER_LINK_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
//			}
//		}
//	}
//};
//

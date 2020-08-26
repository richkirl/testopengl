#pragma comment (lib, "OpenGL32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <cassert>
#include <vector>
#include <sstream>
#include <fstream>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#ifndef TESTRENDER_HPP
#define TESTRENDER_HPP
class testRender
{
public:
	
	GLuint LoadShaders(const std::string &vertex_file_path, const std::string &fragment_file_path);
	GLuint LoadImage(const std::string& path);
	void initializegl();
	void resizeGL(int, int);
	void paintGL(int, int);
	void update();
	void timer();
	void event();
	GLuint CreateVertexBuf(static const GLfloat& g_vertex_buffer_data,GLuint* vertexbuf);
	GLuint CreateColorBuf(static const GLfloat& g_color_buffer_data,GLuint* clrbuf);
	GLuint CreateUVBuf(static const GLfloat& g_uv_buffer_data,GLuint* uvbufr);
	GLFWwindow* window;
	unsigned char* qdata;
	GLuint ProgramID;
	GLuint textureID;
private:
	void _processing();
	void _draw();



	GLuint VertexShaderID ;
	GLuint FragmentShaderID;
	std::string VertexShaderCode;
	std::string FragmentShaderCode;
	std::ifstream VertexShaderStream;
	std::ifstream FragmentShaderStream;
	GLint Result;
	int InfoLogLength;
	char const* VertexSourcePointer;
	char const* FragmentSourcePointer;
	GLuint VertexArrayID;
	
	int qwidth, height, cnt;
	//GLuint ProgramID;

};
#endif // TESTRENDER_HPP

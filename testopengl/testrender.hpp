#pragma comment (lib, "OpenGL32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <gl/glew.h>
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
	void CreateVertexBuf(static const GLfloat& g_vertex_buffer_data);
	void CreateColorBuf(static const GLfloat& g_color_buffer_data);
	void CreateUVBuf(static const GLfloat& g_uv_buffer_data);
	GLFWwindow* window;
	unsigned char* qdata;
	GLuint ProgramID;
	GLuint textureID;
	GLuint vrtbuf;
	GLuint clrbuf;
	GLuint uvbufr;

	GLuint VertexShaderID;
	GLuint FragmentShaderID;
private:
	void _processing();
	void _draw();



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

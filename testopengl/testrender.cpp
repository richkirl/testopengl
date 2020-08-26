#include "testrender.hpp"
//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace glm;
GLuint testRender::LoadShaders(const std::string& vertex_file_path, const std::string& fragment_file_path)
{
    this->VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    this->FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    this->VertexShaderStream.open(vertex_file_path, std::ios::in);
    if (VertexShaderStream.is_open())
    {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    }
    this->FragmentShaderCode;
    this->FragmentShaderStream.open(fragment_file_path, std::ios::in);
    if (FragmentShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }
    this->Result = GL_FALSE;
    
    std::cout << "Компиляция шейдера : " << vertex_file_path << std::endl;
    this->VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(this->VertexShaderID, 1, &this->VertexSourcePointer, NULL);
    glCompileShader(this->VertexShaderID);
    glGetShaderiv(this->VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(this->VertexShaderID, GL_INFO_LOG_LENGTH, &this->InfoLogLength);
    if (this->InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(static_cast<__int64>(this->InfoLogLength) + 1);
        glGetShaderInfoLog(VertexShaderID, this->InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        std::cout << &VertexShaderErrorMessage[0] << std::endl;
    }
    std::cout << "Компиляция шейдера : " << fragment_file_path << std::endl;
    this->FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(this->FragmentShaderID, 1, &this->FragmentSourcePointer, NULL);
    glCompileShader(this->FragmentShaderID);
    glGetShaderiv(this->FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(this->FragmentShaderID, GL_INFO_LOG_LENGTH, &this->InfoLogLength);
    if (this->InfoLogLength > 0) {
        std::vector<char> FragmentShaderErrorMessage(static_cast<__int64>(this->InfoLogLength) + 1);
        glGetShaderInfoLog(this->FragmentShaderID, this->InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        std::cout << &FragmentShaderErrorMessage[0] << std::endl;
    }
    std::cout << "Создаем шейдерную программу и привязываем шейдеры к ней" << std::endl;
    this->ProgramID = glCreateProgram();
    glAttachShader(this->ProgramID, VertexShaderID);
    glAttachShader(this->ProgramID, FragmentShaderID);
    glLinkProgram(this->ProgramID);
    glGetProgramiv(this->ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(this->ProgramID, GL_INFO_LOG_LENGTH, &this->InfoLogLength);
    if (this->InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(static_cast<__int64>(this->InfoLogLength) + 1);
        glGetProgramInfoLog(this->ProgramID, this->InfoLogLength, NULL, &ProgramErrorMessage[0]);
        std::cout << &ProgramErrorMessage[0] << std::endl;
    }
    glDeleteShader(this->VertexShaderID);
    glDeleteShader(this->FragmentShaderID);
    return ProgramID;
}

GLuint testRender::LoadImage(const std::string& path)
{

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    this->qdata = stbi_load(path.c_str(), &this->qwidth, &this->height, &this->cnt, 0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->qwidth, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->qdata);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    return *this->qdata;
    stbi_image_free(this->qdata);
    
}

void testRender::initializegl()
{
    int er = glfwInit();
    assert(er);
    glfwWindowHint(GLFW_SAMPLES, 4);
    paintGL(1024, 768);
    glfwMakeContextCurrent(this->window);
    glewExperimental = true;
    int ui = glewInit();
    assert(!ui);
    this->VertexArrayID;
    glGenVertexArrays(1, &this->VertexArrayID);
    glBindVertexArray(this->VertexArrayID);
}

void testRender::resizeGL(int, int)
{
}

void testRender::paintGL(int x,int y)
{
    this->window = glfwCreateWindow(x, y, "Tutorial 01", NULL, NULL);
    assert(this->window);
}

void testRender::update()
{
}

void testRender::timer()
{
}

void testRender::event()
{
}

GLuint testRender::CreateVertexBuf(static const GLfloat& g_vertex_buffer_data, GLuint* vertexbuf)
{
    //GLuint* vert = &vertexbuffer;
    glGenVertexArrays(1, vertexbuf);
    glBindBuffer(GL_ARRAY_BUFFER, *vertexbuf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), &(g_vertex_buffer_data), GL_STATIC_DRAW);
    return *vertexbuf;
}

GLuint testRender::CreateColorBuf(static const GLfloat& g_color_buffer_data, GLuint* clrbuf)
{
    //GLuint colorbuffer;
    //GLuint* clrbf = &colorbuffer;
    glGenBuffers(1, clrbuf);
    glBindBuffer(GL_ARRAY_BUFFER, *clrbuf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), &(g_color_buffer_data), GL_STATIC_DRAW);
    return *clrbuf;
}

GLuint testRender::CreateUVBuf(static const GLfloat& g_uv_buffer_data, GLuint* uvbufr)
{
    //GLuint uvbuffer;
    //GLuint* uvbfr = &uvbuffer;
    glGenBuffers(1, uvbufr);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *uvbufr);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_uv_buffer_data), &(g_uv_buffer_data), GL_STATIC_DRAW);
    return *uvbufr;
}

void testRender::_processing()
{
}

void testRender::_draw()
{
}

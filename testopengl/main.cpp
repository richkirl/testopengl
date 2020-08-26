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
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "testRender.hpp"
using namespace glm;
int main() {
    setlocale(LC_ALL, "Russian");
    testRender Objworker;
    Objworker.initializegl();
    static const GLfloat g_vertex_buffer_data[] = {
       -1.0f,-1.0f,-1.0f, // Треугольник 1 : начало
       -1.0f,-1.0f, 1.0f,
       -1.0f, 1.0f, 1.0f, // Треугольник 1 : конец
        1.0f, 1.0f,-1.0f, // Треугольник 2 : начало
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // Треугольник 2 : конец
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    };
    static const GLfloat g_color_buffer_data[] = {
        0.583f,  0.771f,  0.014f,
        0.609f,  0.115f,  0.436f,
        0.327f,  0.483f,  0.844f,
        0.822f,  0.569f,  0.201f,
        0.435f,  0.602f,  0.223f,
        0.310f,  0.747f,  0.185f,
        0.597f,  0.770f,  0.761f,
        0.559f,  0.436f,  0.730f,
        0.359f,  0.583f,  0.152f,
        0.483f,  0.596f,  0.789f,
        0.559f,  0.861f,  0.639f,
        0.195f,  0.548f,  0.859f,
        0.014f,  0.184f,  0.576f,
        0.771f,  0.328f,  0.970f,
        0.406f,  0.615f,  0.116f,
        0.676f,  0.977f,  0.133f,
        0.971f,  0.572f,  0.833f,
        0.140f,  0.616f,  0.489f,
        0.997f,  0.513f,  0.064f,
        0.945f,  0.719f,  0.592f,
        0.543f,  0.021f,  0.978f,
        0.279f,  0.317f,  0.505f,
        0.167f,  0.620f,  0.077f,
        0.347f,  0.857f,  0.137f,
        0.055f,  0.953f,  0.042f,
        0.714f,  0.505f,  0.345f,
        0.783f,  0.290f,  0.734f,
        0.722f,  0.645f,  0.174f,
        0.302f,  0.455f,  0.848f,
        0.225f,  0.587f,  0.040f,
        0.517f,  0.713f,  0.338f,
        0.053f,  0.959f,  0.120f,
        0.393f,  0.621f,  0.362f,
        0.673f,  0.211f,  0.457f,
        0.820f,  0.883f,  0.371f,
        0.982f,  0.099f,  0.879f
    };
    static const GLfloat g_uv_buffer_data[] = {
0.333866f, 1.0f-1.000000f,
0.000000f, 1.0f-1.000000f,
0.000000f, 1.0f-0.667266f,
0.333866f, 1.0f-0.667266f,
0.333866f, 1.0f-0.332734f,
0.666134f, 1.0f-0.332734f,
0.333866f, 1.0f-0.332734f,
0.333866f, 1.0f-0.000000f,
0.666134f, 1.0f-0.000000f,
1.000000f, 1.0f-0.332734f,
0.666134f, 1.0f-0.332734f,
0.666134f, 1.0f-0.000000f,
0.000000f, 1.0f-0.332734f,
0.000000f, 1.0f-0.000000f,
0.333866f, 1.0f-0.000000f,
0.333866f, 1.0f-0.667266f,
0.000000f, 1.0f-0.667266f,
0.333866f, 1.0f-0.667266f,
0.666134f, 1.0f-0.332734f,
0.333866f, 1.0f-0.332734f,
0.666134f, 1.0f-0.667266f,
    };
    
    GLuint vertexbuffer;
    glGenVertexArrays(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), &(g_vertex_buffer_data), GL_STATIC_DRAW);
        
    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), &(g_color_buffer_data), GL_STATIC_DRAW);
         
    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_uv_buffer_data), &(g_uv_buffer_data), GL_STATIC_DRAW);
    const std::string path = "sea1.jpg";
   
    Objworker.LoadImage(path);
    const std::string VertexShader = "SimpleVertexShader.vertexshader";
    const std::string FragmentShader = "SimpleFragmentShader.fragmentshader";
    Objworker.LoadShaders(VertexShader, FragmentShader);
    assert(Objworker.ProgramID);
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    glm::mat4 View = glm::lookAt(
        glm::vec3(4, 3, 3), 
        glm::vec3(0, 0, 0), 
        glm::vec3(0, 1, 0)  
    );
     glm::mat4 Model = glm::mat4(1.0f);  
    glm::mat4 MVP = Projection * View * Model;
	glfwSetInputMode(Objworker.window, GLFW_STICKY_KEYS, GL_TRUE);
	do{

        GLuint MatrixID = glGetUniformLocation(Objworker.ProgramID, "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, *(&vertexbuffer));
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 0,(GLvoid*)0);
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, *(&colorbuffer));
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(GLvoid*)0);
        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, *(&uvbuffer));
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,0, (GLvoid*)0);
        glUseProgram(Objworker.ProgramID);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, Objworker.textureID);
        glActiveTexture(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, Objworker.textureID);
        glUniform1i(glGetUniformLocation(Objworker.ProgramID, "sea1.jpg"), 0);
        
		glDrawArrays(GL_TRIANGLES, 0,6*6); 
		glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);

        // позиция
        glm::vec3 position = glm::vec3(0, 0, 5);
        // горизонтальный угол
        float horizontalAngle = 3.14f;
        // вертикальный угол
        float verticalAngle = 0.0f;
        // поле обзора
        float initialFoV = 45.0f;

        float speed = 3.0f; // 3 units / second
        float mouseSpeed = 0.005f;
        double *xpos=0, *ypos=0;
        //glfwGetCursorPos(window,xpos, ypos);
        //glfwSetCursorPos(window, 1024 / 2, 768 / 2);


        // Направление
        glm::vec3 direction(
            cos(verticalAngle)* sin(horizontalAngle),
            sin(verticalAngle),
            cos(verticalAngle)* cos(horizontalAngle)
        );
        // Вектор, указывающий направление вправо от камеры
        glm::vec3 right = glm::vec3(
            sin(horizontalAngle - 3.14f / 2.0f),
            0,
            cos(horizontalAngle - 3.14f / 2.0f)
        );

        glm::vec3 up = glm::cross(right, direction);

        // Проекционная матрица: Поле обзора = FoV, отношение сторон 4 к 3, плоскости отсечения 0.1 и 100 юнитов
        glm::mat4 ProjectionMatrix = glm::perspective(glm::radians(initialFoV), 4.0f / 3.0f, 0.1f, 100.0f);
        // Матрица камеры
        glm::mat4 ViewMatrix = glm::lookAt(
            position,           // Позиция камеры
            position + direction, // Направление камеры
            up                  // Вектор "Вверх" камеры
        );
        double currentTime = glfwGetTime();
        float deltaTime = float(currentTime);
        float FoV = initialFoV - 5;



        // Движение вперед
        if (glfwGetKey(Objworker.window,GLFW_KEY_UP) == GLFW_PRESS) {
            position += direction * deltaTime * speed;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        // Движение назад
        if (glfwGetKey(Objworker.window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            position -= direction * deltaTime * speed;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        // Стрэйф вправо
        if (glfwGetKey(Objworker.window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            position += right * deltaTime * speed;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        // Стрэйф влево
        if (glfwGetKey(Objworker.window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            position -= right * deltaTime * speed;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        glm::mat4 ModelMatrix = glm::mat4(1.0);
        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
		glfwSwapBuffers(Objworker.window);
		glfwPollEvents();
	} while (glfwGetKey(Objworker.window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(Objworker.window) == 0);
    glfwTerminate();
 
    return 0;
}
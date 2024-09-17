#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
int g_windowSizeX = 640;
int g_windowSizeY = 480;
void glfwWindowSizeCallBack(GLFWwindow* pWindow, int width, int height) // функция при измение размеров окна
{

    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY); // где мы хотим рисовать 0 0 от левого нижнего угла начинаем рисовать и во весь размер окна;
}
void glfwKeyCallback(GLFWwindow* pWindow,int key,int scancode,int action,int mode)
{
    if (key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS) // если нажата клавиша esc, то закрываем окно
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
   
    /* Иницилизация */
    if (!glfwInit())
    {
        cout << " Внимание : glfwInit - не запустилась " << endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	
    /* Размер окна, указания */
    GLFWwindow* pWindow = glfwCreateWindow(g_windowSizeX,g_windowSizeY, "Battle Tank", nullptr, nullptr);
    if (!pWindow)
    {
		 cout << " Внимание : glfwTerminate - не запустилась " << endl;
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallBack); // при изменение размеров окна
    glfwSetKeyCallback(pWindow, glfwKeyCallback); // при нажатиее клавиш

    /* Указания в какое окно применять OpenGL */
    glfwMakeContextCurrent(pWindow);

    if(!gladLoadGL())
	{
		cout<<"GLAD !load"<<endl;
		return -1;
	}
	cout<<" Renderer "<<glGetString(GL_RENDERER)<<endl; 
	cout<<" OpenGL version "<<glGetString(GL_VERSION)<<endl;
	
	
	glClearColor(0,1,0,1); // Добавляем зеленый свет в буфер света
	
  
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Очищаем буфер света */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Меняем  буфер */
        glfwSwapBuffers(pWindow);

        /* Обработка ивентов нажатие клавиш, измение размера окна */
        glfwPollEvents();
    }

    glfwTerminate(); // Освобождение ресурсов
    return 0;
}
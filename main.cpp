#include <GLFW/glfw3.h>

#include "inputManager.hpp"
#include "main.hpp"

void initInput(InputManager<int>& inputManager)
{
    inputManager.addInput(ESCAPE,GLFW_KEY_ESCAPE,ImEnumInputType::PRESSED);
    inputManager.addInput(FORWARD,GLFW_KEY_UP,ImEnumInputType::NO_REPEAT);
    inputManager.addInput(BACK,GLFW_KEY_DOWN,ImEnumInputType::NO_REPEAT);
    inputManager.addInput(LEFT,GLFW_KEY_LEFT,ImEnumInputType::NO_REPEAT);
    inputManager.addInput(RIGHT,GLFW_KEY_RIGHT,ImEnumInputType::NO_REPEAT);
}

int main()
{
    if(!glfwInit())
        return EXIT_FAILURE;
    
    GLFWwindow* window = glfwCreateWindow(800,600,"Input manager", NULL, NULL);

    InputManager<int> inputManager(window);

    initInput(inputManager);

    while (!glfwWindowShouldClose(window) && !inputManager.isPressed(ESCAPE))
    {
        inputManager.update();

        if(inputManager.isPressed(FORWARD))
            std::cout << "Forward" << std::endl;
        if(inputManager.isPressed(BACK))
            std::cout << "Back" << std::endl;
        if(inputManager.isPressed(LEFT))
            std::cout << "Left" << std::endl;
        if(inputManager.isPressed(RIGHT))
            std::cout << "Right" << std::endl;

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
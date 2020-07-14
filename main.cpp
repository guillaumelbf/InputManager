#include <GLFW/glfw3.h>
#include <iostream>


#include "inputManager.hpp"
#include "main.hpp"

int main()
{
    if(!glfwInit())
        return EXIT_FAILURE;
    
    GLFWwindow* window = glfwCreateWindow(800,600,"Input manager", NULL, NULL);

    InputManager<InputId> inputManager(window);

    initInput(inputManager);

    while (!glfwWindowShouldClose(window) && !inputManager.isPressed(InputId::ESCAPE))
    {
        glfwPollEvents();
        inputManager.update();

        double cursorPosX,cursorPosY;
        inputManager.getCursorPos(cursorPosX,cursorPosY);

        float axisPos;
        axisPos = inputManager.getAxis(GLFW_JOYSTICK_1,0);

        int hat;
        hat = inputManager.getHat(GLFW_JOYSTICK_1,0);

        if(inputManager.isPressed(InputId::CURSOR))
            std::cout << "Cursor pos x : " << cursorPosX << " , " << "Cursor pos y : " << cursorPosY << std::endl;
        if(inputManager.isPressed(InputId::AXIS))
            std::cout << "Axis pos : " << axisPos << std::endl;
        if(inputManager.isPressed(InputId::HAT))
            std::cout << "Hat value : " << hat << std::endl;

        if(inputManager.isPressed(InputId::FORWARD))
            std::cout << "Forward" << std::endl;
        if(inputManager.isPressed(InputId::BACK))
            std::cout << "Back" << std::endl;
        if(inputManager.isPressed(InputId::LEFT))
            std::cout << "Left" << std::endl;
        if(inputManager.isPressed(InputId::RIGHT))
            std::cout << "Right" << std::endl;

        if(inputManager.isPressed(InputId::JOYSTICK0_A))
            std::cout << "Controller 0 button A" << std::endl;
        if(inputManager.isPressed(InputId::JOYSTICK0_B))
            std::cout << "Controller 0 button B" << std::endl;

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}

void initInput(InputManager<InputId>& inputManager)
{
    inputManager.addKeyInput(InputId::ESCAPE,GLFW_KEY_ESCAPE,ImEnumDetectionType::PRESSED);
    
    inputManager.addKeyInput(InputId::FORWARD,GLFW_KEY_UP,ImEnumDetectionType::NO_REPEAT);
    inputManager.addKeyInput(InputId::BACK,GLFW_KEY_DOWN,ImEnumDetectionType::NO_REPEAT);
    inputManager.addKeyInput(InputId::LEFT,GLFW_KEY_LEFT,ImEnumDetectionType::NO_REPEAT);
    inputManager.addKeyInput(InputId::RIGHT,GLFW_KEY_RIGHT,ImEnumDetectionType::NO_REPEAT);

    inputManager.addKeyInput(InputId::CURSOR,GLFW_KEY_F1,ImEnumDetectionType::SWITCH);
    inputManager.addKeyInput(InputId::AXIS,GLFW_KEY_F2,ImEnumDetectionType::SWITCH);
    inputManager.addKeyInput(InputId::HAT,GLFW_KEY_F3,ImEnumDetectionType::SWITCH);

    inputManager.addControllerInput(InputId::JOYSTICK0_A,GLFW_JOYSTICK_1,0,ImEnumDetectionType::PRESSED);
    inputManager.addControllerInput(InputId::JOYSTICK0_B,GLFW_JOYSTICK_1,1,ImEnumDetectionType::PRESSED);
}
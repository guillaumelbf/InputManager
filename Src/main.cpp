#include <GLFW/glfw3.h>
#include <iostream>


#include "../Include/inputManager.hpp"
#include "../Include/main.hpp"

int main()
{
    if(!glfwInit())
        return EXIT_FAILURE;
    
    GLFWwindow* window = glfwCreateWindow(800,600,"Input manager", NULL, NULL);
    glfwSwapInterval(0);

    InputManager inputManager(window);

    initInput(inputManager);

    while (!glfwWindowShouldClose(window) && !inputManager.isPressed("Escape"))
    {
        glfwPollEvents();
        inputManager.update();

        double cursorPosX,cursorPosY;
        inputManager.getCursorPos(cursorPosX,cursorPosY);

        float axisPos;
        axisPos = inputManager.getAxis(GLFW_JOYSTICK_1,0);

        int hat;
        hat = inputManager.getHat(GLFW_JOYSTICK_1,0);

        if(inputManager.isPressed("Mouse1"))
            std::cout << "Left click" << std::endl;
        if(inputManager.isPressed("Mouse2"))
            std::cout << "Right click" << std::endl;


        if(inputManager.isPressed("F1"))
            std::cout << "Cursor pos x : " << cursorPosX << " , " << "Cursor pos y : " << cursorPosY << std::endl;
        if(inputManager.isPressed("F2"))
            std::cout << "Axis pos : " << axisPos << std::endl;
        if(inputManager.isPressed("F3"))
            std::cout << "Hat value : " << hat << std::endl;

        if(inputManager.isPressed("Forward"))
            std::cout << "Forward" << std::endl;
        if(inputManager.isPressed("Back"))
            std::cout << "Back" << std::endl;
        if(inputManager.isPressed("Left"))
            std::cout << "Left" << std::endl;
        if(inputManager.isPressed("Right"))
            std::cout << "Right" << std::endl;

        if(inputManager.isPressed("Joystick1_1"))
            std::cout << "Controller 0 button A" << std::endl;
        if(inputManager.isPressed("Joystick1_2"))
            std::cout << "Controller 0 button B" << std::endl;
        if(inputManager.isPressed("Joystick1_3"))
            std::cout << "Controller 0 button X" << std::endl;
        if(inputManager.isPressed("Joystick1_4"))
            std::cout << "Controller 0 button Y" << std::endl;

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}

void initInput(InputManager& inputManager)
{
    inputManager.addKeyInput("Escape",GLFW_KEY_ESCAPE,ImEnumDetectionType::PRESSED);

    inputManager.addKeyInput("Forward",GLFW_KEY_UP,ImEnumDetectionType::NO_REPEAT);
    inputManager.addKeyInput("Forward",GLFW_KEY_W,ImEnumDetectionType::NO_REPEAT);
    inputManager.addKeyInput("Back",GLFW_KEY_DOWN,ImEnumDetectionType::NO_REPEAT);
    inputManager.addKeyInput("Left",GLFW_KEY_LEFT,ImEnumDetectionType::NO_REPEAT);
    inputManager.addKeyInput("Right",GLFW_KEY_RIGHT,ImEnumDetectionType::NO_REPEAT);

    inputManager.addKeyInput("F1",GLFW_KEY_F1,ImEnumDetectionType::SWITCH);
    inputManager.addKeyInput("F2",GLFW_KEY_F2,ImEnumDetectionType::SWITCH);
    inputManager.addKeyInput("F3",GLFW_KEY_F3,ImEnumDetectionType::SWITCH);

    inputManager.addMouseInput("Mouse1",GLFW_MOUSE_BUTTON_1,ImEnumDetectionType::PRESSED);
    inputManager.addMouseInput("Mouse2",GLFW_MOUSE_BUTTON_2,ImEnumDetectionType::PRESSED);

    inputManager.addControllerInput("Joystick1_1",GLFW_JOYSTICK_1,0,ImEnumDetectionType::NO_REPEAT);
    inputManager.addControllerInput("Joystick1_2",GLFW_JOYSTICK_1,1,ImEnumDetectionType::NO_REPEAT);
    inputManager.addControllerInput("Joystick1_3",GLFW_JOYSTICK_1,2,ImEnumDetectionType::NO_REPEAT);
    inputManager.addControllerInput("Joystick1_4",GLFW_JOYSTICK_1,3,ImEnumDetectionType::NO_REPEAT);
}
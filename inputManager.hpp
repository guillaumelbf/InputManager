#pragma once

    #include <unordered_map>
    #include <string>
    #include <iostream>

    #include <GLFW/glfw3.h>

    enum class ImEnumInputType
    {
        SWITCH,
        PRESSED,
        NO_REPEAT
    };

    template <typename T>
    class InputManager
    {
    private:
        struct Input
        {
            ImEnumInputType inputType;
            int key;
            bool isPressed;
            bool isReleased;
        };
        GLFWwindow* _window;
        std::unordered_map<T,Input> _inputList;
    public:
        InputManager(GLFWwindow* window)
        {
            _window = window;
        }

        ~InputManager(){}

        void addInput(T id, int key, ImEnumInputType inputType)
        {
            _inputList.insert({id,{inputType,key,false,true}});
        }

        void update()
        {
            glfwPollEvents();

            for (auto i = _inputList.begin(); i != _inputList.end(); i++)
            {
                Input& input = i->second;

                if(input.inputType == ImEnumInputType::NO_REPEAT)
                    input.isPressed = false;

                if(!input.isReleased && glfwGetKey(_window,input.key) != GLFW_RELEASE)
                    continue;
                
                if(input.inputType == ImEnumInputType::SWITCH)
                {
                    if(glfwGetKey(_window,input.key))
                    {
                        input.isPressed = input.isPressed ? false : true;
                        input.isReleased = false;
                    }
                    else if(glfwGetKey(_window,input.key) == GLFW_RELEASE)
                    {
                        input.isReleased = true;
                    }
                }
                else
                {
                    if(glfwGetKey(_window,input.key))
                    {
                        input.isPressed = true;
                        input.isReleased = false;
                    }
                    else if(glfwGetKey(_window,input.key) == GLFW_RELEASE)
                    {
                        input.isPressed = false;
                        input.isReleased = true;
                    }
                }
            }
            
        }

        bool isPressed(T id)
        {
            Input& input = _inputList.at(id);
            bool isPressed = input.isPressed;

            return isPressed;
        }

        bool isReleased(T id)
        {
            return _inputList.at(id).isReleased;
        }
    };
    
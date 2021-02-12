#pragma once

    enum class InputId
    {
        R_CLICK,
        L_CLICK,
        ESCAPE,
        FORWARD,
        BACK,
        LEFT,
        RIGHT,
        CURSOR,
        JOYSTICK0_A,
        JOYSTICK0_B,
        AXIS,
        HAT
    };

    void initInput(InputManager<InputId>& inputManager);

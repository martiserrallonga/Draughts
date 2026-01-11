#pragma once

class IInputHandler {
public:
    virtual ~IInputHandler() = default;
    virtual void onClick() = 0;
    virtual void onDrag() = 0;
};
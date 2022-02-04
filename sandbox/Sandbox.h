#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace box
{
    struct size
    {
        int width;
        int height;
    };
    class Sandbox
    {   
    private:
        
    public:
        GLFWwindow* m_Window;
        GLFWmonitor* m_Monitor;
        size m_WinSize;
        size m_MonitorSize;
        Sandbox();
        ~Sandbox();
        inline GLFWwindow* GetWindow() const {return m_Window;}
    public:
        virtual void RenderInit() {}
        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
    };
}
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

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
        float m_Delta;
        float m_CurrentTime, m_LastTime;
    public:
        GLFWwindow* m_Window;
        GLFWmonitor* m_Monitor;
        size m_WinSize;
        size m_MonitorSize;
        Sandbox();
        ~Sandbox();
        inline GLFWwindow* GetWindow() const {return m_Window;}
        float GetDelta();
        void SetIcon(const std::string& icon_path);
        void UpdateDelta();
    public:
        virtual void RenderInit() {}
        virtual void OnUpdate() {}
        virtual void OnRender() {}
    };
}
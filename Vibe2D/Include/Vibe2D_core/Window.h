#pragma once

#include "vibepch.h"
#include "Vibe2D_core/core.h"
#include "Events/Event.h"

namespace Vibe2D 
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Hieght;

        WindowProps(const std::string& title = "Vibe2D Physics Engine",
                    unsigned int width = 1240,
                    unsigned int hieght = 720)
                : Title(title), Width(width), Hieght(hieght)
        {
        }
    };

// Abstract interface class representing a desktop system based Window 
    class VIBE2D_API Window 
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0; // Triggered once per frame to swap framebuffers and poll device input events

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHieght() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        // Factory pattern instantiator method that must be written by the platform layer target
        static Window* Create(const WindowProps& props = WindowProps());
    };




}
#pragma once

#include "Events/Event.h"


namespace Vibe2D
{
    class VIBE2D_API KeyEvent : public Event
    {
    public:
        // Every key event needs to let the engine inspect which key was touched
        inline int GetKeyCode() const { return m_KeyCode; }   //getter

         //filter
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int keycode)
            : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

// 2. THE KEY PRESSED EVENT (Triggered on hardware key down)
    class VIBE2D_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount; // 0 = first press, 1+ = user holding the button down
    };

 // 3. THE KEY RELEASED EVENT (Triggered on hardware key up)
    class VIBE2D_API KeyReleasedEvent : public KeyEvent 
    {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

}
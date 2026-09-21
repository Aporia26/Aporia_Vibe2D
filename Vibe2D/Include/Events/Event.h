#pragma once

#include <string>       
#include <functional>   
#include <ostream>      
#include <sstream>
#include "Vibe2D_core/core.h"


/* Events are currently blocking in Vibe2D engine, ie whenever an event 
  is it shall be immediately be handled right then and there untill then
   our engine window stops. Better strategy is to use a buffer event bus. */

namespace Vibe2D
{

enum class EventType 
{
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};


 enum EventCategory 
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput       = BIT(1),
        EventCategoryKeyboard    = BIT(2),
        EventCategoryMouse       = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

//#define EVENT_CLASS_TYPE(type)\
//                              static EventType GetStaticType() { return EventType::##type; }\
//                              virtual EventType GetEventType() const override { return GetStaticType(); }\
//                              virtual const char* GetName() const override { return #type; }
//#define EVENT_CLASS_CATEGORY(category)\
//                              virtual int GetCategoryFlags const override { return category; }

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } virtual EventType GetEventType() const override { return GetStaticType(); } virtual const char* GetName() const override { return #type; }

// FIXED: Packaged as a clean, single-line token string block that shields the '|' operator!
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return (int)(category); }



//The Abstract Data Packet
class VIBE2D_API Event
{
    friend class EventDispatcher;
public:
    virtual ~Event() = default; // Added missing virtual destructor for clean polymorphism

    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const {return GetName();}


    //category filter
    inline bool IsInCategory(EventCategory category)
    {
       return (GetCategoryFlags() & (int)category) !=0; 
    }
protected:
    bool m_Handled = false;
};
// The Automatic Brain Router Template
class EventDispatcher 
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event)
            : m_Event(event) {}

        // Automatically evaluates type safety and executes your bound functions!
        template<typename T>
        bool Dispatch(EventFn<T> func) 
        {
            if (m_Event.GetEventType() == T::GetStaticType()) 
            {
                // Execute function and merge result into 'Handled' status registry
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    // Formatting support for spdlog engine logger 
    inline std::ostream& operator<<(std::ostream& os, const Event& e) 
    {
        return os << e.ToString();
    }


}
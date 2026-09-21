#include <Vibe2D.h>
#include <iostream>

//This is our .exe that is build using our engine files .dll

class Sandbox : public Vibe2D::Application
{
public:
    Sandbox()
    {
        
    }
    ~Sandbox()override
    {
        
    }

};

namespace Vibe2D{

    Application* CreateApplication()
    {
        return new Sandbox();
    }

}
/*
Vute-x86 [Version updating Tool (Experimental app) for Windows 32bit platform]
*/


#include <Windows.h>
#include "app/application.h"



int __stdcall WinMain(HINSTANCE hinst, HINSTANCE hprev, LPSTR cmd, int mode)
{
    Vute::Application app(cmd);
    return app.exec();
}

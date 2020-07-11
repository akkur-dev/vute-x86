#include "application.h"




namespace Vute
{
    Application::Application(std::string_view cmdLine) : m_rcfile("resources/VuteTest")
    {}

    Application::~Application()
    {}

    int32_t Application::exec()
    {
        // test file reading
        std::wstring wstr;
        m_rcfile.read(wstr);

        return 0;
    }
}
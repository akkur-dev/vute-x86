#pragma once
#include <string_view>
#include "IO/rcfile/resourcefile.h"



namespace Vute
{
    class Application final
    {
    public:
        Application(std::string_view cmdLine);
        ~Application();

        int32_t exec();

    private:
        IO::ResourceFile m_rcfile;
        
    };
}

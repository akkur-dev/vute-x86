#pragma once
#include "../filestream.h"



namespace Vute::IO
{
    class ResourceFile final : public FileStream<wchar_t>
    {
    public:
        ResourceFile(std::string_view name, std::string_view ext = ".rc");
        ~ResourceFile();
    };
}
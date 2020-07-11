#include "resourcefile.h"




namespace Vute::IO
{
    ResourceFile::ResourceFile(std::string_view name, std::string_view ext) : FileStream(name, ext)
    {
    }

    ResourceFile::~ResourceFile()
    {
    }
}
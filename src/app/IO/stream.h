#pragma once
#include <string>



namespace Vute::IO
{
    template<typename CharT>
    class IStream
    {
    public:        
        virtual ~IStream() = default;

        virtual size_t read(std::basic_string<CharT>& inbuf) = 0;
        virtual size_t write(const std::basic_string<CharT>& outbuf) = 0;

    protected:
        IStream() = default;
    };
}
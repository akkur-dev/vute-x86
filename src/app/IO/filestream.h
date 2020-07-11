#pragma once
#include "stream.h"



namespace Vute::IO
{
    // enumeration of the file opening modes (for reading/for writing)
    enum class OpenMode
    {
        Read,
        Write
    };
    

    // file stream class
    template<typename CharT>
    class FileStream : public IStream<CharT>
    {
    public:
        FileStream(std::string_view name, std::string_view ext);
        virtual         ~FileStream();

        virtual size_t  read(std::basic_string<CharT>& inbuf) override;
        virtual size_t  write(const std::basic_string<CharT>& outbuf) override;

    protected:
        errno_t         _open(OpenMode mode);
        int32_t         _close();
        size_t          _calculateSize();

    private:
        FILE*           m_handle;
        std::string     m_filename;        
        bool            m_isOpened;
    };    
}

#include "filestream.inl"
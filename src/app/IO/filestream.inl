//#include "filestream.h"



namespace Vute::IO
{
    template<typename CharT>
    inline FileStream<CharT>::FileStream(std::string_view name, std::string_view ext) 
        : m_handle(nullptr), m_filename(std::string(name) + std::string(ext)), m_isOpened(false)
    {
        // if character type isn't char or wchar_t - assertion error:
        static_assert(std::is_same_v<CharT, char> || std::is_same_v<CharT, wchar_t>);
    }

    template<typename CharT>
    inline FileStream<CharT>::~FileStream()
    {}

    template<typename CharT>
    inline size_t FileStream<CharT>::read(std::basic_string<CharT>& inbuf)
    {
        // stream size in bytes
        size_t _szbuf = 0;

        _open(OpenMode::Read);
        // receiving stream size:
        _szbuf = _calculateSize();
        // choosing size of input buffer:
        inbuf.resize(_szbuf / sizeof(CharT));
        // reading file to the input buffer:
        _szbuf = fread_s(inbuf.data(), _szbuf, sizeof(CharT), inbuf.size(), m_handle);
        _close();

        return _szbuf;
    }

    template<typename CharT>
    inline size_t FileStream<CharT>::write(const std::basic_string<CharT>& outbuf)
    {
        // stream size in bytes
        size_t _szbuf = 0;

        _open(OpenMode::Write);
        // writing output buffer to the file:
        _szbuf = fwrite(outbuf.data(), sizeof(CharT), outbuf.size(), m_handle);
        _close();

        return _szbuf;
    }

    template<typename CharT>
    inline errno_t FileStream<CharT>::_open(OpenMode mode)
    {
        // string literals for providing to 'fopen' function
        std::string_view _om = (mode == OpenMode::Read) ? "rb" : "wb";
        // opening file stream:
        errno_t _status = fopen_s(&m_handle, m_filename.data(), _om.data());
        // setting flag:
        m_isOpened = (bool)!_status;

        return _status;
    }

    template<typename CharT>
    inline int32_t FileStream<CharT>::_close()
    {
        // closing file stream:
        int32_t _status = fclose(m_handle);
        // setting flag:
        m_isOpened = (bool)_status;

        return _status;
    }

    template<typename CharT>
    inline size_t FileStream<CharT>::_calculateSize()
    {
        size_t _sz = 0;

        if (m_isOpened)
        {
            fseek(m_handle, 0, SEEK_END);
            _sz = ftell(m_handle);
            fseek(m_handle, 0, SEEK_SET);
        }
        return _sz;
    }
}
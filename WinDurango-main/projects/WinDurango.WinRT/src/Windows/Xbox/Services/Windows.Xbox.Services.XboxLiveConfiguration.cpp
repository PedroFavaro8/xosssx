#include "Windows.Xbox.Services.XboxLiveConfiguration.h"
#include "WinDurangoWinRT.h"

std::wstring ExtractAttribute(const std::wstring& xml, const std::wstring& attr)
{
    std::wstring key = attr + L"=\"";

    size_t start = xml.find(key);
    if (start == std::wstring::npos) return L"";

    start += key.length();
    size_t end = xml.find(L"\"", start);
    if (end == std::wstring::npos) return L"";

    return xml.substr(start, end - start);
}

std::wstring ReadFile(const std::wstring& path)
{
    FILE* f = _wfopen(path.c_str(), L"rb");
    if (!f)
        return L"";

    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);

    std::string buffer(size, '\0');
    fread(buffer.data(), 1, size, f);
    fclose(f);

    int len = MultiByteToWideChar(CP_UTF8, 0, buffer.data(), (int)buffer.size(), NULL, 0);
    std::wstring wstr(len, 0);
    MultiByteToWideChar(CP_UTF8, 0, buffer.data(), (int)buffer.size(), &wstr[0], len);

    return wstr;
}

namespace winrt::Windows::Xbox::Services::implementation
{
    hstring XboxLiveConfiguration::TitleId()
    {
        auto xml = ReadFile(L"AppxManifest.xml");
        auto titleId = ExtractAttribute(xml, L"TitleId");
        return titleId.c_str();
    }
    hstring XboxLiveConfiguration::PrimaryServiceConfigId()
    {
        auto xml = ReadFile(L"AppxManifest.xml");
        auto primaryServiceConfigId = ExtractAttribute(xml, L"PrimaryServiceConfigId");
        return primaryServiceConfigId.c_str();
    }
    hstring XboxLiveConfiguration::SandboxId()
    {
        return L"RETAIL";
    }
}

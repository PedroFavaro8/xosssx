#include "WinDurango.Host/ApiContract.h"

extern "C" WINDURANGO_API_EXPORT bool WinDurangoApiGetInfo(WinDurangoApiInfo* info)
{
    if (!info)
    {
        return false;
    }
    info->abi_version = WinDurangoApiAbiVersion;
    info->name = "WinDurangoApiFixture";
    info->version = "0.1.0";
    return true;
}

extern "C" WINDURANGO_API_EXPORT bool WinDurangoApiInitialize(const WinDurangoApiHost* host)
{
    if (!host || host->abi_version != WinDurangoApiAbiVersion)
    {
        return false;
    }
    if (host->log)
    {
        host->log("fixture initialized");
    }
    return true;
}

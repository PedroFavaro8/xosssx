#pragma once

#include <cstdint>

namespace windurango::host
{
    inline constexpr std::uint64_t MinimumPhysicalMemoryBytes = 8ull * 1024ull * 1024ull * 1024ull;
    inline constexpr double MinimumReportedMemoryGiB = 7.5;
}

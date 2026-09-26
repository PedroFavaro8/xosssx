#pragma once

#include <cstddef>
#include <filesystem>

namespace windurango::host {

struct ApiLoadResult {
    std::size_t discovered = 0;
    std::size_t loaded = 0;
};

ApiLoadResult LoadApis(const std::filesystem::path& directory);
bool LoadApiFile(const std::filesystem::path& file);

} // namespace windurango::host

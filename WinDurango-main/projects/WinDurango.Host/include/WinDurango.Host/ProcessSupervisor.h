#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace windurango::host {

struct LaunchPlan {
    std::filesystem::path dashboard;
    std::vector<std::filesystem::path> background;
    std::filesystem::path background_root;
    std::filesystem::path api_root;
    std::wstring run_token;
};

int LaunchDashboard(const LaunchPlan& plan);
int LaunchPackage(const std::filesystem::path& package);

} // namespace windurango::host

/*
 * Created by DexrnZacAttack on 1/23/26 using zPc-i2.
 * WinDurango.Common::Config
 */
#pragma once
#include "Interfaces/Storage/Directory.h"
#include "Interfaces/Storage/File.h"
#include "WinDurango.Common/exports.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

/*
 * TODO: Make it to write back
 */
namespace wd::common
{
    class WD_API Config
    {
    public:
        Config() : pDirectory(nullptr), RO(false)
        {
        }

        Config(std::shared_ptr<interfaces::storage::Directory> dir, bool ReadOnly = false) : pDirectory(dir), RO(ReadOnly)
        {
        }

        bool parse();

        /*
         * Operator Overloading
         * https://en.cppreference.com/w/cpp/language/operators.html
         */
        const nlohmann::json &operator[](std::string node);

        const nlohmann::json& jsonData();

    private:
        std::shared_ptr<interfaces::storage::Directory> pDirectory;
        std::shared_ptr<interfaces::storage::File> pFile = nullptr;
        bool RO;
        nlohmann::json data;
    };
} // namespace wd::common

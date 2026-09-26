//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#pragma once
#include "File.h"
#include <filesystem>
#include <memory>

// Windows.h defines CreateFile as a macro (CreateFileA/W); scope it out only
// for our declarations and restore it afterwards so Win32/ATL headers keep
// working in the same translation unit.
#if defined(CreateFile)
#pragma push_macro("CreateFile")
#undef CreateFile
#define WD_CREATEFILE_MACRO_RESTORED 1
#endif

namespace wd::common::interfaces::storage
{
    // TODO should we have separate project for interfaces?

    /*
     * Interface for storage management, to be impl'd for uwp and crossplat
     *
     * We don't need any args for the constructor
     * nor any vars bc this is an abstraction.
     */
    class Directory
    {
      public:
        Directory()
        {
        }

        virtual ~Directory() = default;

        virtual bool open() = 0;
        virtual std::shared_ptr<File> CreateFile(
            std::filesystem::path
                path) = 0; // todo maybe return stream type, todo can we use this in uwp context??? I forgor
        virtual std::shared_ptr<Directory> CreateFolder(std::filesystem::path path) = 0;

        virtual std::filesystem::path dirpath() = 0;

        virtual bool rename(std::string) = 0;
        virtual bool remove() = 0;
        virtual bool move(std::filesystem::path path) = 0;
        virtual bool copy(std::filesystem::path path) = 0;
        virtual bool dirExists(std::string) = 0;
        virtual bool fileExists(std::string) = 0;
    };
} // namespace wd::common::interfaces::storage

#if defined(WD_CREATEFILE_MACRO_RESTORED)
#pragma pop_macro("CreateFile")
#undef WD_CREATEFILE_MACRO_RESTORED
#endif

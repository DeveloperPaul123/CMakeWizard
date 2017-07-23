#include "cmake_library.h"

cmake_library::cmake_library(const std::string& name, const std::vector<cmake_package>& dependencies)
    : _name(name)
{
    _deps = dependencies;
}

cmake_library::cmake_library(const cmake_library& other)
{
    _name = other._name;
    _deps = other._deps;
}

cmake_library::cmake_library(cmake_library&& other) noexcept
{
    _name = other._name;
    _deps = other._deps;
}

cmake_library& cmake_library::operator=(const cmake_library& other)
{
    _name = other._name;
    _deps = other._deps;
    return *this;
}

cmake_library& cmake_library::operator=(cmake_library&& other) noexcept
{
    _name = other._name;
    _deps = other._deps;
    return *this;
}

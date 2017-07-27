#include "CmakeLibrary.h"

CmakeLibrary::CmakeLibrary(const std::string& name, const std::vector<CmakePackage>& dependencies)
    : _name(name)
{
    _deps = dependencies;
}

CmakeLibrary::CmakeLibrary(const CmakeLibrary& other)
{
    _name = other._name;
    _deps = other._deps;
}

CmakeLibrary::CmakeLibrary(CmakeLibrary&& other) noexcept
{
    _name = other._name;
    _deps = other._deps;
}

CmakeLibrary& CmakeLibrary::operator=(const CmakeLibrary& other)
{
    _name = other._name;
    _deps = other._deps;
    return *this;
}

CmakeLibrary& CmakeLibrary::operator=(CmakeLibrary&& other) noexcept
{
    _name = other._name;
    _deps = other._deps;
    return *this;
}

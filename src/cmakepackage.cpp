#include "CmakePackage.h"

CmakePackage::CmakePackage(const std::string& name, bool required, const std::string& required_version)
{
    _name = name;
    _req = required;
    _version = required_version;
}

CmakePackage::CmakePackage(const CmakePackage& other)
{
    _name = other._name;
    _req = other._req;
    _version = other._version;
}

CmakePackage::CmakePackage(CmakePackage&& other) noexcept
{
    _name = other._name;
    _req = other._req;
    _version = other._version;  
}

CmakePackage& CmakePackage::operator=(const CmakePackage& other)
{
    _name = other._name;
    _req = other._req;
    _version = other._version;
    return *this;
}

CmakePackage& CmakePackage::operator=(CmakePackage&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }
    _name = other._name;
    _req = other._req;
    _version = other._version;
    return *this;
}

std::string CmakePackage::name() const
{
    return _name;
}

bool CmakePackage::is_required() const
{
    return _req;
}

std::string CmakePackage::version() const
{
    return _version;
}

std::ostream& operator<<(std::ostream& stream, const CmakePackage& package)
{
    std::string required_string = package._req ? "REQUIRED" : "";

    stream << "find_package(" << package._name << " " << required_string;
    if (package._version.length() > 0)
    {
        stream << " VERSION " << package._version;
    }
    // close the parenthesis. 
    stream << ")";
    return stream;
}

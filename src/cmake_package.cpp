#include "cmake_package.h"

cmake_package::cmake_package(const std::string& name, bool required, const std::string& required_version)
{
    _name = name;
    _req = required;
    _version = required_version;
}

cmake_package::cmake_package(const cmake_package& other)
{
    _name = other._name;
    _req = other._req;
    _version = other._version;
}

cmake_package::cmake_package(cmake_package&& other) noexcept
{
    _name = other._name;
    _req = other._req;
    _version = other._version;  
}

cmake_package& cmake_package::operator=(const cmake_package& other)
{
    _name = other._name;
    _req = other._req;
    _version = other._version;
    return *this;
}

cmake_package& cmake_package::operator=(cmake_package&& other) noexcept
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

std::string cmake_package::name() const
{
    return _name;
}

bool cmake_package::is_required() const
{
    return _req;
}

std::string cmake_package::version() const
{
    return _version;
}

std::ostream& operator<<(std::ostream& stream, const cmake_package& package)
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

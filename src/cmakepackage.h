#pragma once

#include <string>

class CmakePackage
{
    std::string _name{""};
    bool _req{true};
    std::string _version{ "" };
public:
	explicit CmakePackage(const std::string &name, bool required = true, const std::string& required_version = "");
	CmakePackage(const CmakePackage& other);
    CmakePackage(CmakePackage &&other) noexcept;
	CmakePackage& operator=(const CmakePackage& other);
    CmakePackage& operator=(CmakePackage&& other) noexcept;
    std::string name() const;
    bool is_required() const;
    std::string version() const;
    friend std::ostream& operator<<(std::ostream& stream, const CmakePackage &package);
};
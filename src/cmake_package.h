#pragma once

#include <string>

class cmake_package
{
    std::string _name{""};
    bool _req{true};
    std::string _version{ "" };
public:
	explicit cmake_package(const std::string &name, bool required = true, const std::string& required_version = "");
	cmake_package(const cmake_package& other);
    cmake_package(cmake_package &&other) noexcept;
	cmake_package& operator=(const cmake_package& other);
    cmake_package& operator=(cmake_package&& other) noexcept;
    std::string name() const;
    bool is_required() const;
    std::string version() const;
    friend std::ostream& operator<<(std::ostream& stream, const cmake_package &package);
};
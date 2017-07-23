#pragma once

#include <string>
#include "cmake_package.h"
#include <vector>

class cmake_library
{
public:
	cmake_library(const std::string &name, const std::vector<cmake_package> &dependencies);
	cmake_library(const cmake_library & other);
    cmake_library(cmake_library &&other) noexcept;
	cmake_library& operator=(const cmake_library &other);
    cmake_library& operator=(cmake_library &&other) noexcept;
private:
	std::string _name;
	std::vector<cmake_package> _deps;
};

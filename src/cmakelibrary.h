#pragma once

#include <string>
#include "CmakePackage.h"
#include <vector>

class CmakeLibrary
{
public:
	CmakeLibrary(const std::string &name, const std::vector<CmakePackage> &dependencies);
	CmakeLibrary(const CmakeLibrary & other);
    CmakeLibrary(CmakeLibrary &&other) noexcept;
	CmakeLibrary& operator=(const CmakeLibrary &other);
    CmakeLibrary& operator=(CmakeLibrary &&other) noexcept;
private:
	std::string _name;
	std::vector<CmakePackage> _deps;
};

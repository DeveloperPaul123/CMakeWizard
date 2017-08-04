#include "CmakeLibrary.h"

CmakeLibrary::CmakeLibrary(const QString& name, const QList<CmakePackage>& dependencies)
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

void CmakeLibrary::setName(const QString& name)
{
	_name = name;
}

QString CmakeLibrary::name() const
{
	return _name;
}

void CmakeLibrary::setPackages(const QList<CmakePackage>& packages)
{
	_deps = packages;
}

QList<CmakePackage> CmakeLibrary::packages() const
{
	return _deps;
}



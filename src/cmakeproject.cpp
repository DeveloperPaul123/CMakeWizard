#include "CmakeProject.h"

CmakeProject::CmakeProject()
{
}

CmakeProject::CmakeProject(const QString& name)
	: _name(name)
{
}

CmakeProject::~CmakeProject()
{
}

void CmakeProject::setName(const QString& name)
{
	_name = name;
}

QString CmakeProject::name() const
{
	return _name;
}

void CmakeProject::setDirectory(const QString& directory)
{
	_directory = directory;
}

QString CmakeProject::directory() const
{
	return _directory;
}

void CmakeProject::setOptions(const QList<CmakeOption>& options)
{
	_options = options;
}

QList<CmakeOption> CmakeProject::options() const
{
	return _options;
}

void CmakeProject::setLibraries(const QList<CmakeLibrary>& libraries)
{
	_libraries = libraries;
}

QList<CmakeLibrary> CmakeProject::libraries() const
{
	return _libraries;
}

void CmakeProject::setPackages(const QList<CmakePackage>& packages)
{
	_packages = packages;
}

QList<CmakePackage> CmakeProject::packages() const
{
	return _packages;
}

void CmakeProject::addOption(const CmakeOption& option)
{
	_options.append(option);
}

void CmakeProject::addLibrary(const CmakeLibrary& library)
{
	_libraries.append(library);
}

void CmakeProject::addPackage(const CmakePackage& package)
{
	_packages.append(package);
}

void CmakeProject::setInstallable(const bool& installable)
{
	_isInstallable = installable;
}

bool CmakeProject::isInstallable() const
{
	return _isInstallable;
}

#include "CmakePackage.h"

CmakePackage::CmakePackage(const QString& name, bool required, const QString& required_version)
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
	_hasComponents = other._hasComponents;
	_headerOnly = other._headerOnly;
	_components = other._components;
	_externalAddScript = other._externalAddScript;
}

CmakePackage::CmakePackage(CmakePackage&& other) noexcept
{
    _name = other._name;
    _req = other._req;
    _version = other._version;
	_hasComponents = other._hasComponents;
	_headerOnly = other._headerOnly;
	_components = other._components;
	_externalAddScript = other._externalAddScript;
}

CmakePackage& CmakePackage::operator=(const CmakePackage& other)
{
    _name = other._name;
    _req = other._req;
    _version = other._version;
	_hasComponents = other._hasComponents;
	_headerOnly = other._headerOnly;
	_components = other._components;
	_externalAddScript = other._externalAddScript;
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
	_hasComponents = other._hasComponents;
	_headerOnly = other._headerOnly;
	_components = other._components;
	_externalAddScript = other._externalAddScript;
    return *this;
}

QString CmakePackage::name() const
{
    return _name;
}

bool CmakePackage::is_required() const
{
    return _req;
}

QString CmakePackage::version() const
{
    return _version;
}

void CmakePackage::setComponents(const QStringList& components)
{
	_components = components;
}

QStringList CmakePackage::components() const
{
	return _components;
}

bool CmakePackage::hasComponents() const
{
	return _hasComponents;
}

void CmakePackage::setIsHeaderOnly(const bool& is_header_only)
{
	_headerOnly = is_header_only;
}

bool CmakePackage::isHeaderOnly() const
{
	return _headerOnly;
}

void CmakePackage::setExternalAddScript(const QString& script_path)
{
	_externalAddScript = script_path;
}

QString CmakePackage::externalAddScript() const
{
	return _externalAddScript;
}

std::ostream& operator<<(std::ostream& stream, const CmakePackage& package)
{
    std::string required_string = package._req ? "REQUIRED" : "";

    stream << "find_package(" << package._name.toStdString() << " " << required_string;
    if (package._version.length() > 0)
    {
        stream << " VERSION " << package._version.toStdString();
    }
    // close the parenthesis. 
    stream << ")";
    return stream;
}

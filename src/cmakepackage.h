#pragma once

#include <QStringList>

class CmakePackage
{
	bool _req{ true };
	bool _hasComponents{ false };
	bool _headerOnly{ false };
	QStringList _components;
	QString _externalAddScript;
	QString _name{""};
	QString _version{ "" };

public:
	explicit CmakePackage(const QString &name, bool required = true, const QString& required_version = "");
	CmakePackage(const CmakePackage& other);
    CmakePackage(CmakePackage &&other) noexcept;
	CmakePackage& operator=(const CmakePackage& other);
    CmakePackage& operator=(CmakePackage&& other) noexcept;
	QString name() const;
    bool is_required() const;
	QString version() const;
	void setComponents(const QStringList &components);
	QStringList components() const;
	bool hasComponents() const;
	void setIsHeaderOnly(const bool &is_header_only);
	bool isHeaderOnly() const;
	void setExternalAddScript(const QString &script_path);
	QString externalAddScript() const;
    friend std::ostream& operator<<(std::ostream& stream, const CmakePackage &package);
};

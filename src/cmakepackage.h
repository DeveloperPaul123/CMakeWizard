#pragma once

#include <QString>

class CmakePackage
{
	QString _name{""};
    bool _req{true};
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
    friend std::ostream& operator<<(std::ostream& stream, const CmakePackage &package);
};

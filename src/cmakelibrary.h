#pragma once

#include "CmakePackage.h"

#include <QList>

class CmakeLibrary
{
public:
	CmakeLibrary(const QString &name, const QList<CmakePackage> &dependencies);
	CmakeLibrary(const CmakeLibrary & other);
    CmakeLibrary(CmakeLibrary &&other) noexcept;
	CmakeLibrary& operator=(const CmakeLibrary &other);
    CmakeLibrary& operator=(CmakeLibrary &&other) noexcept;

	void setName(const QString &name);
	QString name() const;
	void setPackages(const QList<CmakePackage> &packages);
	QList<CmakePackage> packages() const;

private:
	QString _name;
	QList<CmakePackage> _deps;
};

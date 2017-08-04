#pragma once

#include <QString>
#include <QList>

#include "CmakeOption.h"
#include "CmakePackage.h"
#include "CmakeLibrary.h"

class CmakeProject {
public:
	CmakeProject();
	explicit CmakeProject(const QString &name);
	~CmakeProject();

	void setName(const QString &name);
	QString name() const;
	void setDirectory(const QString &directory);
	QString directory() const;
	void setOptions(const QList<CmakeOption> &options);
	QList<CmakeOption> options() const;
	void setLibraries(const QList<CmakeLibrary> &libraries);
	QList<CmakeLibrary> libraries() const;
	void setPackages(const QList<CmakePackage> &packages);
	QList<CmakePackage> packages() const;

	void addOption(const CmakeOption &option);
	void addLibrary(const CmakeLibrary &library);
	void addPackage(const CmakePackage &package);

	void setInstallable(const bool &installable);
	bool isInstallable() const;

private:
	QString _name;
	QString _directory;
	QList<CmakeOption> _options;
	QList <CmakeLibrary> _libraries;
	QList<CmakePackage> _packages;
	bool _isInstallable = false;
};

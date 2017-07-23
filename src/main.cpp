#include <QApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QTextStream>

#include "mainwindow.h"

#include <iostream>


QCoreApplication* createApplication(int &argc, char *argv[])
{
    if(argc >= 2) {
        return new QCoreApplication(argc, argv);
    }
	return new QApplication(argc, argv);
}

int moveDirectory(const QString& source_dir, const QString& target_dir)
{
	QDir source(source_dir);
	QDir target(target_dir);
	
	if (!source.exists())
	{
		std::cout << "Source directory: " << source_dir.toStdString() << " does not exist." << std::endl;
		return -1;
	}
	if(!target.exists())
	{
		std::cout << "Target directory does not exist. Creating now...";
		auto ok = target.mkpath(target_dir);
		if (ok) {
			std::cout << "Directory created." << std::endl;
		}
		else
		{
			std::cout << "Could not create directory." << std::endl;
			return -1;
		}
	}

	// check if a cmakecache exists
	auto fullPath = QString("%1\\%2").arg(source_dir, "CMakeCache.txt");
	QFileInfo cmake_cache_info(fullPath);
	if(!cmake_cache_info.exists())
	{
		std::cout << "CMakeCache.txt does not exist in source path. Exiting." << std::endl;
		return -1;
	}
	// file exists
	QFile cmake_cache(cmake_cache_info.absolutePath());
	if(cmake_cache.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&cmake_cache);
		while(!stream.atEnd())
		{
			QString line = stream.readLine();
		}

		cmake_cache.close();
	}
	else
	{
		std::cout << "Unable to open CMakeCache.txt file. Exiting." << std::endl;
		return -1;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	QScopedPointer<QCoreApplication> app(createApplication(argc, argv));
    app->setApplicationName("CmakeWizard");
    app->setApplicationVersion(QString::fromStdString(CMAKE_WIZARD_VERSION));

	if (qobject_cast<QApplication *>(app.data())) {
        MainWindow * main_window = new MainWindow();
		// start GUI version...
		main_window->show();
	}
	else {
        // start non-GUI version...
        QCommandLineParser parser;
        parser.setApplicationDescription("Cmake Wizard command line. ");
        parser.addHelpOption();
        parser.addVersionOption();
        parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source directory to copy. Must contain cmakecache.txt."));
        parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

        // A boolean option with a single name (-p)
        QCommandLineOption showProgressOption("p", QCoreApplication::translate("main", "Show progress during copy"));
        parser.addOption(showProgressOption);

        // A boolean option with multiple names (-f, --force)
        QCommandLineOption forceOption(QStringList() << "f" << "force",
            QCoreApplication::translate("main", "Overwrite existing files."));
        parser.addOption(forceOption);

        // An option with a value
        QCommandLineOption sourceDirectoryOption(QStringList() << "s" << "source-directory",
            QCoreApplication::translate("main", "Copy source files from <directory>."),
            QCoreApplication::translate("main", "directory"));
        parser.addOption(sourceDirectoryOption);

        // An option with a value
        QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory",
            QCoreApplication::translate("main", "Copy all source files into <directory>."),
            QCoreApplication::translate("main", "directory"));
        parser.addOption(targetDirectoryOption);

        parser.process(*app.data());
		auto source_dir = parser.value(sourceDirectoryOption);
		auto target_dir = parser.value(targetDirectoryOption);

		return moveDirectory(source_dir, target_dir);
	}

	return app->exec();
}

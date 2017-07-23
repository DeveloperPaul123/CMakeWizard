#include <QApplication>
#include <QCommandLineParser>
#include <QDir>

#include "mainwindow.h"

#include <iostream>


QCoreApplication* createApplication(int &argc, char *argv[])
{
    if(argc >= 2) {
        return new QCoreApplication(argc, argv);
    }
	return new QApplication(argc, argv);
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
        QString source_dir = parser.value(sourceDirectoryOption);
        QDir dir(source_dir);
        if(!dir.exists())
        {
//            std::cout << "Given directory: " << source_dir.toStdString() << " does not exist." << std::endl;
            return -1;
        }
        return 0;
	}

	return app->exec();
}
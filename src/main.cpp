#include <QApplication>

#include "mainwindow.h"


QCoreApplication* createApplication(int &argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
		if (!qstrcmp(argv[i], "-no-gui"))
			return new QCoreApplication(argc, argv);
	return new QApplication(argc, argv);
}

int main(int argc, char* argv[])
{
	QScopedPointer<QCoreApplication> app(createApplication(argc, argv));
	MainWindow main_window;
	if (qobject_cast<QApplication *>(app.data())) {
		// start GUI version...
		main_window.show();
	}
	else {
		// start non-GUI version...
	}

	return app->exec();
}
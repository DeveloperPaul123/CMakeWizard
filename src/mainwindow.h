#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cmake_package.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onChangeOutputDirectoryClicked();
    void onAddThirdParyLibraryClicked();
    void onRemoveThirdPartyLibraryClicked();
    void onAddBuiltLibraryClicked();
    void onRemoveBuiltLibraryClicked();
    void onGenerateClicked();

    void onProjectTypeChanged(int index);


private:
    void addPackageToTable(const cmake_package &package) const;
    void addPackageToTable(const int &index) const;
    Ui::MainWindow *ui;
    void connectSignalsToSlots() const;
};

#endif // MAINWINDOW_H

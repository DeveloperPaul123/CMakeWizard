#include "mainwindow.h"
#include "ui_mainwindow.h"

// standard includes
#include <iostream>

// qt includes
#include <QFileDialog>
#include <QToolTip>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	setWindowTitle(tr("CMakeWizard"));

    // setup gui connections.
    connectSignalsToSlots();
}

void MainWindow::onChangeOutputDirectoryClicked()
{
    auto curDir = QDir().absolutePath();
    auto directory = QFileDialog::getExistingDirectory(this,
        tr("Open an existing directory."),
        curDir,
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (directory.length() > 0)
    {
        ui->outputDirectoryLineEdit->setText(directory);
    }
}

void MainWindow::onAddThirdParyLibraryClicked() const
{
    auto numRows = ui->thirdPartyLibrariesTableWidget->rowCount();
    addPackageToTable(numRows);
}

void MainWindow::onRemoveThirdPartyLibraryClicked() const
{
    auto currentRow = ui->thirdPartyLibrariesTableWidget->currentRow();
    ui->thirdPartyLibrariesTableWidget->removeRow(currentRow);
}

void MainWindow::onAddBuiltLibraryClicked()
{
	// TODO: Add a way to add a library
}

void MainWindow::onRemoveBuiltLibraryClicked()
{
    auto currentRow = ui->projectLibrariesTableWidget->currentRow();
    ui->projectLibrariesTableWidget->removeRow(currentRow);
}

void MainWindow::onGenerateClicked()
{
    auto projectName = ui->projectNameLineEdit->text();
    if(projectName.isEmpty())
    {
        QToolTip::showText(ui->projectNameLineEdit->mapToGlobal(QPoint()), tr("Project name is required!"));
        return;
    }
}

void MainWindow::onProjectTypeChanged(int index)
{
    switch(index)
    {
    case 0:
        // console application
        // TODO: Remove qt5 from the table
        break;
    case 1:
        // qt application
        cmake_package qt("Qt5", true, "5.9");
        addPackageToTable(qt);
        break;
    }
}

void MainWindow::addPackageToTable(const cmake_package& package) const
{
    auto rowCount = ui->thirdPartyLibrariesTableWidget->rowCount();
    addPackageToTable(rowCount);
    ui->thirdPartyLibrariesTableWidget->item(rowCount, 0)->setText(QString::fromStdString(package.name()));
    ui->thirdPartyLibrariesTableWidget->item(rowCount, 1)->setText(QString::fromStdString(package.version()));
    auto checkBox = dynamic_cast<QCheckBox*>(ui->thirdPartyLibrariesTableWidget->cellWidget(rowCount, 2));
    if(checkBox)
    {
        checkBox->setChecked(package.is_required());
    }
}

void MainWindow::addPackageToTable(const int& index) const
{
    ui->thirdPartyLibrariesTableWidget->insertRow(index);

    auto nameWidget = new QTableWidgetItem("Library name");
    auto versionWidget = new QTableWidgetItem("Any");

    ui->thirdPartyLibrariesTableWidget->setItem(index, 0, nameWidget);
    ui->thirdPartyLibrariesTableWidget->setItem(index, 1, versionWidget);
    ui->thirdPartyLibrariesTableWidget->setCellWidget(index, 2, new QCheckBox("Required"));
}

void MainWindow::connectSignalsToSlots() const
{
    // button callbacks.
    connect(ui->changeOutputButton, SIGNAL(clicked()), this, SLOT(onChangeOutputDirectoryClicked()));
    connect(ui->addPackageButton, SIGNAL(clicked()), this, SLOT(onAddThirdParyLibraryClicked()));
    connect(ui->removePackageButton, SIGNAL(clicked()), this, SLOT(onRemoveThirdPartyLibraryClicked()));
    connect(ui->addLibraryButton, SIGNAL(clicked()), this, SLOT(onAddBuiltLibraryClicked()));
    connect(ui->removeLibraryButton, SIGNAL(clicked()), this, SLOT(onRemoveBuiltLibraryClicked()));
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(onGenerateClicked()));
    
    // combo box call back. 
    connect(ui->projectTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onProjectTypeChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

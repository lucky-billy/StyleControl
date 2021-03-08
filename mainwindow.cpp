#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->action_style1, &QAction::triggered, [&](){ changeStyle(0); });
    connect(ui->action_style2, &QAction::triggered, [&](){ changeStyle(1); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeStyle(int type)
{
    QString fileName = "";
    switch ( type )
    {
    case 1: fileName = "gray.css"; break;
    default: {
        this->setStyleSheet("");
        return;
    };
    }

    QString path = ":/qss/"+ fileName;
    QFile file(path);

    if ( file.open(QFile::ReadOnly) )
    {
        QString qss = QLatin1String(file.readAll());
        this->setStyleSheet(qss);
        file.close();
    }
}

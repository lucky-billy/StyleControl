#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("MyQSSDemo");

    connect(ui->horizontalSlider, &QSlider::valueChanged, [&](int value){ ui->progressBar->setValue(value); });

    connect(ui->action_style_original,  &QAction::triggered, [&](){ changeStyle(0); });
    connect(ui->action_style_black,     &QAction::triggered, [&](){ changeStyle(1); });
    connect(ui->action_style_blue,      &QAction::triggered, [&](){ changeStyle(2); });
    connect(ui->action_style_brown,     &QAction::triggered, [&](){ changeStyle(3); });
    connect(ui->action_style_gray,      &QAction::triggered, [&](){ changeStyle(4); });
    connect(ui->action_style_green,     &QAction::triggered, [&](){ changeStyle(5); });
    connect(ui->action_style_silvery,   &QAction::triggered, [&](){ changeStyle(6); });
    connect(ui->action_style_white,     &QAction::triggered, [&](){ changeStyle(7); });
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
    case 1: fileName = "black.qss"; break;
    case 2: fileName = "blue.qss"; break;
    case 3: fileName = "brown.qss"; break;
    case 4: fileName = "gray.qss"; break;
    case 5: fileName = "green.qss"; break;
    case 6: fileName = "silvery.qss"; break;
    case 7: fileName = "white.qss"; break;
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
    computer = new Wordle();

    ui->outputConsole->setVisible(true);
    ui->outputConsole->setText(toQString(dialogue::welcome));

    ui->outputConsole->setVisible(true);
    QTimer::singleShot(4000, this, [this] () { ui->outputConsole->setText(toQString(RoomDialogue::lr_n)); });

    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0)->getImage());
    updateImage(imageDes);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//method that converts c string to QString
QString MainWindow::toQString(string s)
{
    QString str = QString::fromUtf8(s.c_str());
    return str;
}

//updates the image lable depending on location
void MainWindow::updateImage(QString dest)
{
    QPixmap pix(dest);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}



void MainWindow::on_right_button_clicked(){

}

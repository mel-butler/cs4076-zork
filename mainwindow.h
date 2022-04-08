#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ZorkUL.h"
#include "wordle.h"
#include "dialogue.h"

#include <string>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateImage(QString dest);
    void imageDestination(QString &pic);
    void parseInput(const string &input);

private slots:
    void on_right_button_clicked();
   // void on_left_button_clicked();

private:
    QString imageDes;
    QString toQString(string s);
    Ui::MainWindow *ui;
    string dir;
    ZorkUL *zork;
    Wordle *computer;
};

#endif // MAINWINDOW_H
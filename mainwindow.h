#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>

#include <QPushButton>
#include "src/map.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generateButtons();

private:
    Ui::MainWindow *ui;
    MapWidget *mp_wid;
    QWidget *widg;
    QPushButton *butCircle;
    QPushButton *increase_but;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "global.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer tim;

private:
    Ui::MainWindow *ui;
public slots:
    void onTimOut();
private slots:
    void on_btnSet_clicked();
    void on_btnReset_clicked();

signals:
    void changePort(int);
    void reSet();
};

#endif // MAINWINDOW_H

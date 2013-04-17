#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qmainwindow.h>
#include <qpushbutton.h>
#include "Views/Clocks/AnalogClock.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QPushButton* pushButton;
    AnalogClock* clock;
    
    private slots:
    
    void handleButton();
    void resetColor();
};

#endif // MAINWINDOW_H

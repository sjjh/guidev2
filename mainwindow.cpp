#include "mainwindow.h"
#include <qboxlayout.h>
#include <QString>

#define WINDOW_TITLE    "Clock"

#define WINDOW_HEIGHT   300
#define WINDOW_WIDTH    800

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    // Setup window
    
    this->setWindowTitle(WINDOW_TITLE);
    this->setMinimumSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // Create layout and central widget for window
    
    QVBoxLayout* layout = new QVBoxLayout();
    
    QWidget* centralWidget = new QWidget();
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
}


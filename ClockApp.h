//
//  ClockApp.h
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#ifndef __guidev2__ClockApp__
#define __guidev2__ClockApp__

#include <iostream>
#include <QApplication>
#include "UndoRedo/UndoRedoWindow.h"
#include "mainwindow.h"
#include "UndoRedo/UndoRedoViewController.h"
#include "Model/DataSource.h"
#include "Model/DummyDataSource.h"

/**
 * Represents the clock application.
 */
class ClockApp: public QApplication
{
    Q_OBJECT
    
    private:
    
        MainWindow* mainWindow;
        UndoRedoWindow* undoRedoWindow;
        QAction* showUndoRedoPlaygroundAction;
        UndoRedoViewController* undoRedoViewController;
        DataSource* dataSource;
    
    public:
    
        /**
         * Creates a new ClockApp instance.
         */
        ClockApp(int &argc, char **argv);
    
        /**
         * Destroys the ClockApp object and performs necessary clean up.
         */
        ~ClockApp();
    
        /**
         * Shows main window
         */
        void showMainWindow();

        /**
         * @brief getDataSource
         * @return the DataSource used in the app
         */
        DataSource* getDataSource();

    
    public slots:
    
        /**
         * Show undo redo playground window
         */
        void showUndoRedoPlayGround();
};

#endif /* defined(__guidev2__ClockApp__) */

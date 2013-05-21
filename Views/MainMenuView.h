//
//  MainMenuView.h
//  guidev2
//
//  Created by Jens Meder on 21.05.13.
//
//

#ifndef __guidev2__MainMenuView__
#define __guidev2__MainMenuView__

#include <iostream>
#include <QWidget>
#include <QTabWidget>

class MainMenuView: public QWidget
{
    public:
    
        MainMenuView(QWidget* parent = 0);
        virtual ~MainMenuView();

        QTabWidget* getTabs();

    private:

        QTabWidget* tabs;
};

#endif /* defined(__guidev2__MainMenuView__) */

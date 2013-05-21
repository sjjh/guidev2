//
//  MainMenuView.cpp
//  guidev2
//
//  Created by Jens Meder on 21.05.13.
//
//

#include "MainMenuView.h"
#include <QLayout>

MainMenuView::MainMenuView(QWidget* parent):QWidget(parent)
{
    tabs = new QTabWidget();
    
    setLayout(new QVBoxLayout());
    layout()->addWidget(tabs);
}

MainMenuView::~MainMenuView()
{
    delete tabs;
}

QTabWidget* MainMenuView::getTabs()
{
    return this->tabs;
}

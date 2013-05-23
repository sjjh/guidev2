//
//  ViewController.cpp
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#include "ViewController.h"

ViewController::ViewController(ClockApp* app)
{
    this->app = app;
}

ViewController::~ViewController()
{

}

QWidget* ViewController::getView()
{
    return view;
}
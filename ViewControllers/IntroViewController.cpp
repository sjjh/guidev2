#include "IntroViewController.h"
#include "IntroView.h"

IntroViewController::IntroViewController()
{
    view = new IntroView();
}

IntroViewController::~IntroViewController()
{
    view = NULL;
}

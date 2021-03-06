#ifndef __guidev2__SelectPupilViewController__
#define __guidev2__SelectPupilViewController__

#include "ViewController.h"
#include "ClockApp.h"
#include <QItemSelection>

class SelectPupilViewController: public ViewController
{
    Q_OBJECT

    public:
    
        SelectPupilViewController(ClockApp* app);
        ~SelectPupilViewController();
    
    public slots:
    
        void selectionChanged( const QModelIndex & index );
    
        void startEasyQuiz();
        void startMediumQuiz();
        void startHardQuiz();
    
    private:
    
        Pupil* _selectedPupil;
};

#endif // __guidev2__SelectPupilViewController__

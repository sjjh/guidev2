#ifndef __guidev2__SelectPupilView__
#define __guidev2__SelectPupilView__

#include <QWidget>
#include <QGridLayout>
#include <QList>
#include <QPushButton>
#include <QListView>

class SelectPupilView : public QWidget
{
    Q_OBJECT
    
    public:
    
        SelectPupilView(QWidget *parent = 0);
        virtual ~SelectPupilView();
    
        QListView* getPupilList();
        QPushButton* easyButton();
        QPushButton* mediumButton();
        QPushButton* hardButton();

    private:
    
        QListView* pupilList;
        QPushButton* _easyButton;
        QPushButton* _mediumButton;
        QPushButton* _hardButton;
    
    signals:
    
    public slots:
    
};

#endif // __guidev2__SelectPupilView__

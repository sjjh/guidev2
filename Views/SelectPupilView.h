#ifndef __guidev2__SelectPupilView__
#define __guidev2__SelectPupilView__

#include <QWidget>
#include <QGridLayout>
#include <QList>
#include <QPushButton>

class SelectPupilView : public QWidget
{
    Q_OBJECT
public:
    SelectPupilView(QWidget *parent = 0);
    ~SelectPupilView();

private:
    QGridLayout *mainLayout;
    QList<QPushButton*> *pupilButtons;
    QPushButton *homeButton;
    
signals:
    
public slots:
    
};

#endif // __guidev2__SelectPupilView__

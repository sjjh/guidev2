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

private:
    QListView* pupilList;
    
signals:
    
public slots:
    
};

#endif // __guidev2__SelectPupilView__

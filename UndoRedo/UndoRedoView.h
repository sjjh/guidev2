#ifndef __guidev2__UndoRedoView__
#define __guidev2__UndoRedoView__

#include <QWidget>
#include "UndoRedoCanvasView.h"
#include <QSlider>

class UndoRedoView: public QWidget
{
    Q_OBJECT

    public:
        UndoRedoView(QWidget * parent = 0, Qt::WindowFlags f = 0);
        ~UndoRedoView();

    /**
     * @brief getCanvasView
     * @return returns the canvas you can paint on
     */
    UndoRedoCanvasView* getCanvasView();
    
    public slots:
    
        void transparencyChanged(int);


private:

    UndoRedoCanvasView* canvasView;
    QSlider* transparencySlider;
};

#endif // __guidev2__UndoRedoView__

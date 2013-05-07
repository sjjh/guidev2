#ifndef __guidev2__UndoRedoView__
#define __guidev2__UndoRedoView__

#include <QWidget>
#include "UndoRedoCanvasView.h"
//#include "UndoRedoLabelView.h"

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

    /**
     * @brief getLabelView
     * @return returns the descriptive label
     */
//    UndoRedoLabelView* getLabelView()


private:
//    UndoRedoLabelView* labelView;
    UndoRedoCanvasView* canvasView;
};

#endif // __guidev2__UndoRedoView__

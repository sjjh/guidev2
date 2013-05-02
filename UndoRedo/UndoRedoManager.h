//
//  UndoRedoManager.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__UndoRedoManager__
#define __guidev2__UndoRedoManager__

#include <iostream>
#include "Undoable.h"
#include <QStack>
#include <QObject>

class UndoRedoManager: public QObject
{
    Q_OBJECT
    
    private:
    
        UndoRedoManager();
        QStack<Undoable*>* undoStack;
        QStack<Undoable*>* redoStack;
    
    public:

        static UndoRedoManager* instance();
    
        bool canUndo();
        bool canRedo();
        void addUndoable(Undoable*);
    
        ~UndoRedoManager();
    
    public slots:
    
        void undo();
        void redo();
};

#endif /* defined(__guidev2__UndoRedoManager__) */

//
//  UndoRedoManager.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "UndoRedoManager.h"

UndoRedoManager* UndoRedoManager::instance()
{
    static UndoRedoManager* instance;
    
    if(!instance)
    {
        instance = new UndoRedoManager();
    }
    
    return instance;
}

UndoRedoManager::UndoRedoManager()
{
    undoStack = new QStack<Undoable*>();
    redoStack = new QStack<Undoable*>();
}

UndoRedoManager::~UndoRedoManager()
{
    delete undoStack;
    delete redoStack;
}

void UndoRedoManager::undo()
{
    if(canUndo())
    {
        Undoable* undoable = undoStack->pop();
        redoStack->push(undoable);
    
        undoable->undo();
    }
}

void UndoRedoManager::redo()
{
    if(canRedo())
    {
        Undoable* undoable = redoStack->pop();
        undoStack->push(undoable);

        undoable->redo();
    }
}

void UndoRedoManager::addUndoable(Undoable* undoable)
{
    undoStack->push(undoable);
    
    redoStack->empty();
}

bool UndoRedoManager::canUndo()
{
    return !undoStack->isEmpty();
}

bool UndoRedoManager::canRedo()
{
    return !redoStack->isEmpty();
}
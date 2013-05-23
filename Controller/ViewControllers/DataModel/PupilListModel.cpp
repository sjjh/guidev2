//
//  PupilListModel.cpp
//  guidev2
//
//  Created by Jens Meder on 21.05.13.
//
//

#include "PupilListModel.h"
#include <QModelIndex>

PupilListModel::PupilListModel(DataSource* dataSource)
{
    this->dataSource = dataSource;
}

int PupilListModel::rowCount ( const QModelIndex & parent) const
{
    return dataSource->getAllPupils().length();
}

QVariant PupilListModel::data ( const QModelIndex & index, int role ) const
{
    if ( role == Qt::DisplayRole )
    {
        return dataSource->getAllPupils().at(index.row())->getName();
    }
    return QVariant();
    
}
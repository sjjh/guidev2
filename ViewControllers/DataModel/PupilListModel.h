//
//  PupilListModel.h
//  guidev2
//
//  Created by Jens Meder on 21.05.13.
//
//

#ifndef __guidev2__PupilListModel__
#define __guidev2__PupilListModel__

#include <iostream>
#include <QAbstractListModel>
#include "DataSource.h"

class PupilListModel: public QAbstractListModel
{
    public:
    
        PupilListModel(DataSource* dataSource);
    
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role) const;
    
    private:
    
        DataSource* dataSource;
};

#endif /* defined(__guidev2__PupilListModel__) */

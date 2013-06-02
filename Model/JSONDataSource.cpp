//
//  JSONDataSource.cpp
//  guidev2
//
//  Created by Jens Meder on 22.05.13.
//
//

#define FILENAME        ".pupils.clock"

#define PUPIL_NAME_KEY  "name"

#include "JSONDataSource.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QVariant>
#include <QDataStream>
#include <QDir>

JSONDataSource::JSONDataSource()
{    
}

JSONDataSource::~JSONDataSource()
{
}

void JSONDataSource::save()
{
    if(!isLoaded)
    {
        return;
    }
    
    QJsonDocument doc;
    QJsonArray pupilArray;
    
    for(int i = 0; i < pupils->length();i++)
    {
        pupilArray.append(encodePupil(pupils->at(i)));
    }
    
    doc.setArray(pupilArray);
    
    QFile file(QDir::toNativeSeparators(QDir::homePath())  + "/" + FILENAME);
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    else
    {        
        file.write(doc.toJson());
        file.close();
    }
}

void JSONDataSource::load()
{
    QByteArray data;
    
    QFile file(QDir::toNativeSeparators(QDir::homePath()) + "/" + FILENAME);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    else
    {        
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        
        if(doc.isArray())
        {
            QJsonArray pupilObjects = doc.array();
            for (int i = 0; i < pupilObjects.count(); i++)
            {
                Pupil* p = decode(pupilObjects.at(i).toObject());
                pupils->append(p);
            }
        }
        
        file.close();
        
    }
}

QJsonObject JSONDataSource::encodePupil(Pupil* pupil)
{
    QJsonObject obj;
    obj.insert(PUPIL_NAME_KEY, QJsonValue(pupil->getName()));
    
    return obj;
}

Pupil* JSONDataSource::decode(QJsonObject obj)
{
    Pupil* pupil = new Pupil();
    
    pupil->setName(obj.value(PUPIL_NAME_KEY).toString());
    
    return pupil;
}

#ifndef MYDATASOURCE_H
#define MYDATASOURCE_H

#include "mydatatypes.h"

#include <QList>

class MyDataSource
{
public:
    MyDataSource();

    QList<GeometricShape> getShapes();
};

#endif // MYDATASOURCE_H

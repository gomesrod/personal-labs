#include "mydatasource.h"

#include <algorithm>

using namespace std;

MyDataSource::MyDataSource()
{

}

QList<GeometricShape> MyDataSource::getShapes()
{
    QList<GeometricShape> lst;

    lst.append(GeometricShape(1, "Circle"));
    lst.append(GeometricShape(2, "Square"));
    lst.append(GeometricShape(3, "Triangle"));
    lst.append(GeometricShape(4, "Losangle"));
    lst.append(GeometricShape(5, "Pentagon"));
    lst.append(GeometricShape(6, "Star"));

    return lst;
}

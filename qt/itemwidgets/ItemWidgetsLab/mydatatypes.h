#ifndef MYDATATYPES_H
#define MYDATATYPES_H

#include <QString>

class GeometricShape
{
public:
    GeometricShape() {}

    GeometricShape(int _code, const QString& _desc)
        : code(_code), description(_desc) {}

    int code;
    QString description;
};

#endif // MYDATATYPES_H

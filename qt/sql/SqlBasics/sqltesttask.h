#ifndef SQLTESTTASK_H
#define SQLTESTTASK_H

#include <QObject>

class SqlTestTask : public QObject
{
    Q_OBJECT
public:
    explicit SqlTestTask(QObject *parent = 0);
    
signals:
    void finished();

public slots:
    void run();
    
};

#endif // SQLTESTTASK_H

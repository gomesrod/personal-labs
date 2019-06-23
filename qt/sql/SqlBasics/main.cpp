#include "sqltesttask.h"

#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SqlTestTask* task = new SqlTestTask(&a);

    QCoreApplication::connect(task, SIGNAL(finished()), &a, SLOT(quit()));

    QTimer::singleShot(0, task, SLOT(run()));

    return a.exec();
}

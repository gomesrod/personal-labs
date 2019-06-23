#ifndef SELECTSHAPEDIALOG_H
#define SELECTSHAPEDIALOG_H

#include <QDialog>

class QListWidget;

class SelectShapeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SelectShapeDialog(QWidget *parent = 0);
    
signals:
    
public slots:
    
private:
    void loadList(QListWidget* listWidget);
};

#endif // SELECTSHAPEDIALOG_H

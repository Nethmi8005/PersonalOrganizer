#ifndef BUDGET_H
#define BUDGET_H

#include <QDialog>
#include "database.h"

namespace Ui {
class budget;
}

class budget : public QDialog
{
    Q_OBJECT

public:
    explicit budget(QWidget *parent = nullptr);
    ~budget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::budget *ui;
    Database db;
};

#endif // BUDGET_H

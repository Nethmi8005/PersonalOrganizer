#ifndef INCOME_H
#define INCOME_H

#include <QDialog>
#include "database.h"

namespace Ui {
class Income;
}

class Income : public QDialog
{
    Q_OBJECT

public:
    explicit Income(QWidget *parent = nullptr);
    ~Income();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::Income *ui;
    Database db;
};

#endif // INCOME_H

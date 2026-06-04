#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>
#include "database.h"

namespace Ui {
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::Schedule *ui;
    Database db;
};

#endif // SCHEDULE_H

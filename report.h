#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include "database.h"

namespace Ui {
class report;
}

class report : public QDialog
{
    Q_OBJECT

public:
    explicit report (QWidget *parent = nullptr);
    ~report();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::report *ui;
    Database db;
};

#endif // REPORT_H

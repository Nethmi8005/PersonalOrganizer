#include "report.h"
#include "ui_report.h"
#include "menu.h"
#include <QMessageBox>


report::report(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::report)
{
    ui->setupUi(this);
    db.openDatabase();
}

report::~report()
{
    delete ui;
    db.closeDatabase();
}

void report::on_pushButton_clicked()
{
    menu *cot=new menu();
    this->hide();
    cot->show();

    connect(cot,&menu::destroyed,this,&report::deleteLater);
}
void report::on_pushButton_2_clicked()
{
    QString totalIncome = ui->lineEdit->text();
    QString totalExpenses = ui->lineEdit_2->text();
    QString savings = ui->lineEdit_3->text();

    if (totalIncome.isEmpty() || totalExpenses.isEmpty() || savings.toDouble() == 0.0) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields before saving.");
        return;
    }
    if (db.addReport(totalIncome, totalExpenses, savings)) {
        QMessageBox::information(this, "Success", "Report saved successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to save report.");
    }
}
